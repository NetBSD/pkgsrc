# $NetBSD: Makefile,v 1.40 2001/11/26 13:08:24 martti Exp $
#
# According to AbiSource's explanation of their trademark rights,
# compilations/distributions of AbiWord not provided by AbiSource must
# be named either "AbiWord Personal" or some name completely unlike
# AbiSource's registered trademarks.

DISTNAME=	abiword-${ABIWORD_VERS}
PKGNAME=	abiword-personal-${ABIWORD_VERS}
ABIWORD_VERS=	0.9.5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=abiword/}
DIST_SUBDIR=	abisuite

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.abisource.com/
COMMENT=	Open Source cross-platform word processor

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base

USE_BUILDLINK_ONLY=	# defined

USE_X11=	# defined
USE_GMAKE=	# defined
ALL_TARGET=	compile canonical

OS_CFLAGS=	${CFLAGS}

.if exists(/usr/include/inttypes.h)
OS_CFLAGS+=	-DHAVE_INTTYPE_H=1
.endif

# AbiWord expects the iconv functions to be in the system libraries, so
# unconditionally link against the pkgsrc libiconv.so.
#
XLDFLAGS=	${LDFLAGS} -liconv

MAKE_ENV+=	OS_CFLAGS="${OS_CFLAGS}"
MAKE_ENV+=	XLDFLAGS="${XLDFLAGS}"
MAKE_ENV+=	prefix="${PREFIX}"

MAKE_FLAGS+=	ABI_BUILD_VERSION="${ABIWORD_VERS}"
MAKE_FLAGS+=	UNIX_CAN_BUILD_STATIC=0

WRKSRC=		${WRKDIR}/${DISTNAME}/abi

INSTALL_FILE=		${WRKDIR}/INSTALL
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

FILES_SUBST=		LN=${LN:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

post-install:
	${CHMOD} -R a+r ${PREFIX}/share/AbiSuite
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../converters/libiconv/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
