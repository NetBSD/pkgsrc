# $NetBSD: Makefile,v 1.13 2016/02/26 09:41:07 jperkin Exp $
#

DISTNAME=	validns-0.8
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.validns.net/download/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.validns.net/
COMMENT=	Validns, a high performance DNS/DNSSEC zone validator
LICENSE=	2-clause-bsd

# Depends on perl for make tests

#BUILD_DEPENDS+=	p5-Test-Command-Simple-[0-9]*:../../devel/p5-Test-Command-Simple

#USE_TOOLS+=perl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV.SunOS+=	EXTRALIBS="-lsocket -lnsl"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

#post-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/validns ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/validns.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libjudy/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
