# $NetBSD: bin-install.mk,v 1.4.2.1 2006/10/07 15:36:51 salo Exp $
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

.PHONY: bin-install
.PHONY: do-bin-install do-bin-install-from-source
.PHONY: su-do-bin-install
.PHONY: aquire-bin-install-lock locked-su-do-bin-install release-bin-install-lock

bin-install: \
	do-bin-install \
	do-bin-install-from-source

do-bin-install: su-target
	@${PHASE_MSG} "Binary install for "${PKGNAME_REQD:U${PKGNAME}:Q}

su-do-bin-install: \
	acquire-bin-install-lock \
	locked-su-do-bin-install \
	release-bin-install-lock

acquire-bin-install-lock: \
	acquire-localbase-lock

release-bin-install-lock: \
	release-localbase-lock

locked-su-do-bin-install:
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
	fi

do-bin-install-from-source:
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	if ${PKG_INFO} -qe ${PKGNAME}; then				\
		: "Nothing to do";					\
	else								\
		${STEP_MSG} "No binary package found for ${PKGNAME}; installing from source."; \
		${RECURSIVE_MAKE} ${MAKEFLAGS} DEPENDS_TARGET=${DEPENDS_TARGET:Q} package \
		&& ${RECURSIVE_MAKE} ${MAKEFLAGS} clean;		\
	fi
