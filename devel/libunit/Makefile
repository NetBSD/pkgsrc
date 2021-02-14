# $NetBSD: Makefile,v 1.2 2021/02/14 13:44:34 otis Exp $

PKGNAME=	libunit-${UNIT_VERSION}
DISTNAME=	unit-${UNIT_VERSION}
COMMENT=	Development kit for dynamic web application server

MAINTAINER=	osa@FreeBSD.org

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
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
