# $NetBSD: Makefile,v 1.7 2023/09/01 17:28:28 osa Exp $

PKGNAME=	libunit-${UNIT_VERSION}
DISTNAME=	unit-${UNIT_VERSION}
COMMENT=	Development kit for dynamic web application server

MAINTAINER=	osa@NetBSD.org

DISTINFO_FILE=	${.CURDIR}/../../www/unit/distinfo
PATCHDIR=	${.CURDIR}/../../www/unit/patches

WRKSRC=		${WRKDIR}/${DISTNAME}

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--ld-opt="-L${PREFIX}/lib -R${PREFIX}/lib"
CONFIGURE_ARGS+=	--pkgconfigdir=${PREFIX}/lib/pkgconfig
CONFIGURE_ARGS+=	--no-regex

do-build:
	cd ${WRKSRC} && ${MAKE} build/lib/libunit.a

do-install:
	${MAKE} -C ${WRKSRC} libunit-install DESTDIR=${DESTDIR}

.include "../../www/unit/version.mk"
.include "../../www/unit/Makefile.common"
.include "../../mk/bsd.pkg.mk"
