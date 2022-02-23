# $NetBSD: Makefile,v 1.5 2022/02/23 04:24:37 osa Exp $

PKGNAME=	libunit-${UNIT_VERSION}
DISTNAME=	unit-${UNIT_VERSION}
COMMENT=	Development kit for dynamic web application server

MAINTAINER=	osa@NetBSD.org

DISTINFO_FILE=	${.CURDIR}/../../www/unit/distinfo
PATCHDIR=	${.CURDIR}/../../www/unit/patches

WRKSRC=		${WRKDIR}/${DISTNAME}

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--ld-opt="-L${PREFIX}/lib -R${PREFIX}/lib"
CONFIGURE_ARGS+=	--no-regex

do-build:
	cd ${WRKSRC} && ${MAKE} build/libunit.a

do-install:
	${MAKE} -C ${WRKSRC} libunit-install DESTDIR=${DESTDIR}

.include "../../www/unit/version.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
