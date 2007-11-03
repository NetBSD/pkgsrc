# $NetBSD: bin-install.mk,v 1.16 2007/11/03 10:25:33 rillig Exp $
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
.if ${OPSYS} == "NetBSD"
BINPKG_SITES?= \
	ftp://ftp.NetBSD.org/pub/NetBSD/packages/$${rel}/$${arch}
.else
BINPKG_SITES?=
.endif

.PHONY: bin-install
.PHONY: do-bin-install do-bin-install-from-source
.PHONY: su-do-bin-install
.PHONY: acquire-bin-install-lock locked-su-do-bin-install release-bin-install-lock

bin-install: \
	do-bin-install \
	do-bin-install-from-source

.  if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
do-bin-install: su-do-bin-install
.  else
do-bin-install: su-target
.  endif
	@${PHASE_MSG} "Binary install for "${PKGNAME_REQD:U${PKGNAME}:Q}

su-do-bin-install: \
	acquire-bin-install-lock \
	locked-su-do-bin-install \
	release-bin-install-lock

acquire-bin-install-lock: \
	acquire-localbase-lock

release-bin-install-lock: \
	release-localbase-lock

_BIN_INSTALL_PREPARE_CMD= \
	found=`${PKG_BEST_EXISTS} "${PKGWILDCARD}" || ${TRUE}`;		\
	if [ "$$found" != "" ]; then					\
		${ERROR_MSG} "$$found is already installed - perhaps an older version?"; \
		${ERROR_MSG} "If so, you may wish to \`\`pkg_delete $$found'' and install"; \
		${ERROR_MSG} "this package again by \`\`${MAKE} bin-install'' to upgrade it properly."; \
		exit 1;							\
	fi; \
	rel=${_SHORT_UNAME_R:Q};					\
	arch=${MACHINE_ARCH:Q};						\
	pkg_path=${PKGREPOSITORY:Q};					\
	set args ${BINPKG_SITES}; shift;				\
	for i in "$$@"; do						\
		pkg_path="$$pkg_path;$$i/All";				\
	done;

locked-su-do-bin-install:
.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
	${RUN} ${_BIN_INSTALL_PREPARE_CMD}				\
	${STEP_MSG} "Installing ${PKGNAME} from $$pkg_path";		\
	if ${SETENV} PKG_PATH="$$pkg_path" ${PKG_ADD} -m ${MACHINE_ARCH} -I -p ${_CROSS_DESTDIR}${PREFIX} ${_BIN_INSTALL_FLAGS} ${PKGNAME_REQD:U${PKGNAME}:Q}${PKG_SUFX}; then \
		${ECHO} "Fixing recorded cwd...";			\
		${SED} -e 's|@cwd ${_CROSS_DESTDIR}|@cwd |' ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS > ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS.tmp; \
		${MV} ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS.tmp ${_PKG_DBDIR}/${PKGNAME:Q}/+CONTENTS; \
		${ECHO} "`${PKG_INFO} -e ${PKGNAME_REQD:U${PKGNAME}:Q}` successfully installed."; \
	fi
.else
	${RUN} ${_BIN_INSTALL_PREPARE_CMD}				\
	pkgpattern=${PKGNAME_REQD:U${PKGNAME}:Q};			\
	${STEP_MSG} "Installing $$pkgpattern from $$pkg_path";		\
	if ${SETENV} PKG_PATH="$$pkg_path" ${PKG_ADD} ${_BIN_INSTALL_FLAGS} "$$pkgpattern"; then \
		installed=`${PKG_INFO} -e "$$pkgpattern"`;		\
		${ECHO} "$$installed successfully installed.";		\
	fi
.endif

do-bin-install-from-source:
	${RUN} pkgpattern=${PKGNAME_REQD:U${PKGNAME}:Q};		\
	${PKG_INFO} -qe "$$pkgpattern" || {				\
		${STEP_MSG} "No binary package found for $$pkgpattern; installing from source."; \
		${RECURSIVE_MAKE} ${MAKEFLAGS} DEPENDS_TARGET=${DEPENDS_TARGET:Q} package-install \
		&& ${RECURSIVE_MAKE} ${MAKEFLAGS} clean;		\
	}
