# $NetBSD: Makefile,v 1.57 2002/12/12 01:50:47 hubertf Exp $

# Note to package maintainers:
#
# To update the distfile of this pkg, cd to /usr/src/usr.sbin,
# edit PKGTOOLS_VERSION in lib/version.h to `date +%Y%m%d`, do
# "tar pzvcf pkg_install-`date +%Y%m%d`.tar.gz pkg_install" and upload
# that file to ${MASTER_SITE_LOCAL}.
#
# XXX Modify PKGTOOLS_REQD value in pkgsrc/mk/bsd.pkg.mk to the new
# value ONLY(!) if there is a critical change in the pkg_* tools that
# bsd.pkg.mk and friends rely on.

DISTNAME=		pkg_install-20021123
CATEGORIES=		pkgtools
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/
COMMENT=		NetBSD-current's pkg_* tools

# No special options needed for IPv6 support
WRKSRC=			${WRKDIR}/pkg_install
MAKE_ENV+=		BINDIR=/usr/sbin MANDIR=/usr/share/man NOLINT=1
NO_CONFIGURE=		yes
NO_MTREE=		yes
NO_PKG_REGISTER=	yes
NO_PACKAGE=		No package registration is done
MANCOMPRESSED_IF_MANZ=	yes
BUILD_DEFS+=		MANINSTALL

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
SHLOCK:=	${LOCALBASE}/bin/shlock
.endif

LOCALBASE:=	${PKG_TOOLS_BIN:C|/[^/]?bin$||}
PKG_DBDIR?=		/var/db/pkg

.if ${OPSYS} == "NetBSD" && !exists(/usr/share/tmac/tmac.andoc)
PKG_FAIL_REASON+= "You need to have the 'text' set installed to build this package!"
.endif

.if ${OPSYS} == "SunOS"
MAKEFLAGS+=	NETBSD_COMPATIBLE=YES
MANINSTALL=
MAKE_ENV+=	MANINSTALL= MKMAN=no NOMAN=YES
MAKE_ENV+=	ZOULARISBASE=${ZOULARISBASE}
.endif

.if ${OPSYS} == "OpenBSD"
CPPFLAGS+=		-D__COPYRIGHT\(x\)=\; -D__RCSID\(x\)=\;
MAKE_ENV+=		BINGRP=${BINGRP} BINOWN=${BINOWN}
MAKE_ENV+=		BINDIR=${PKG_TOOLS_BIN}
MAKE_ENV+=		MANDIR=${PKG_TOOLS_BIN}/../man
.endif

.if ${OPSYS} == "Linux"
MAKE_ENV+=		DIGESTDIR=${.CURDIR}/../digest/files
CPPFLAGS+=		-I${DIGESTDIR} -I${DIGESTDIR}
CPPFLAGS+=		-D__COPYRIGHT\(x\)=\; -D__RCSID\(x\)=\;
MAKE_ENV+=		BINGRP=${BINGRP} BINOWN=${BINOWN}
MAKE_ENV+=		BINDIR=${PKG_TOOLS_BIN}
MAKE_ENV+=		MANDIR=${PKG_TOOLS_BIN}/../man
.endif

.if ${OPSYS} == "Darwin"
MAKE_ENV+= 		DIGESTDIR=${.CURDIR}/../digest/files
CPPFLAGS+=		-I${DIGESTDIR} -I${DIGESTDIR}
MAKE_ENV+=		BINGRP=${BINGRP} BINOWN=${BINOWN}
MAKE_ENV+=		BINDIR=${PKG_TOOLS_BIN}
MAKE_ENV+=		MANDIR=${PKG_TOOLS_BIN}/../man
.endif

post-install:
	if [ ! -f ${PKG_DBDIR}/pkgdb.byfile.db ]; then \
		if [ ! -d ${PKG_DBDIR} ]; then \
			${INSTALL_DATA_DIR} ${PKG_DBDIR}; \
		fi; \
		${PKG_ADMIN} rebuild ; \
	fi

.include "../../mk/bsd.pkg.mk"
