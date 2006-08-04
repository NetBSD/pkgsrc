# $NetBSD: bin-install.mk,v 1.3 2006/08/04 20:52:27 rillig Exp $
#

# This file provides the following targets:
#
# bin-install
#	Tries to install a package from a prebuilt binary package, and
#	if that doesn't work, builds the package from source.
#
# The following variables can be set by the pkgsrc user in mk.conf:
#
# PACKAGES
#	This directory is searched before BINPKG_SITES when trying to
#	install binary packages.
#
# BINPKG_SITES
#	A list of URLs where binary packages can be found.
#	See mk/defaults/mk.conf for details.
#

# List of sites carrying binary pkgs. Variables "rel" and "arch" are
# replaced with OS release ("1.5", ...) and architecture ("mipsel", ...)
BINPKG_SITES?= \
	ftp://ftp.NetBSD.org/pub/NetBSD/packages/$${rel}/$${arch}

_SU_BIN_INSTALL_TARGETS=	acquire-bin-install-lock
_SU_BIN_INSTALL_TARGETS+=	locked-su-bin-install
_SU_BIN_INSTALL_TARGETS+=	release-bin-install-lock

.PHONY: acquire-bin-install-lock release-bin-install-lock
acquire-bin-install-lock: acquire-localbase-lock
release-bin-install-lock: release-localbase-lock

# Install binary pkg, without strict uptodate-check first
.PHONY: su-bin-install
su-bin-install: ${_SU_BIN_INSTALL_TARGETS}
.ORDER: ${_SU_BIN_INSTALL_TARGETS}

locked-su-bin-install:
	@found=`${PKG_BEST_EXISTS} \"${PKGWILDCARD}\" || ${TRUE}`;	\
	if [ "$$found" != "" ]; then					\
		${ERROR_MSG} "$$found is already installed - perhaps an older version?"; \
		${ERROR_MSG} "If so, you may wish to \`\`pkg_delete $$found'' and install"; \
		${ERROR_MSG} "this package again by \`\`${MAKE} bin-install'' to upgrade it properly."; \
		exit 1;							\
	fi
	@rel=${_SHORT_UNAME_R:Q};					\
	arch=${MACHINE_ARCH:Q};						\
	pkgpath=${PKGREPOSITORY:Q};					\
	for i in ${BINPKG_SITES}; do					\
		pkgpath="$$pkgpath;$$i/All";				\
	done;								\
	${STEP_MSG} "Installing ${PKGNAME} from $$pkgpath";		\
	if ${SETENV} PKG_PATH="$$pkgpath" ${PKG_ADD} ${_BIN_INSTALL_FLAGS} ${PKGNAME_REQD:U${PKGNAME}:Q}${PKG_SUFX}; then \
		${ECHO} "`${PKG_INFO} -e ${PKGNAME_REQD:U${PKGNAME}:Q}` successfully installed."; \
	else 				 				\
		${SHCOMMENT} "Cycle through some FTP server here";	\
		${STEP_MSG} "No binary package found for ${PKGNAME} -- installing from source"; \
		${RECURSIVE_MAKE} ${MAKEFLAGS} package			\
			DEPENDS_TARGET=${DEPENDS_TARGET:Q}		\
		&& ${RECURSIVE_MAKE} ${MAKEFLAGS} clean;		\
	fi

.PHONY: bin-install
bin-install: su-target
	@${PHASE_MSG} "Binary install for "${PKGNAME_REQD:U${PKGNAME}:Q}
