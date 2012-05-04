# $NetBSD: Makefile,v 1.1.1.1 2012/05/04 23:57:46 pettai Exp $
#

DISTNAME=	validns-0.4
CATEGORIES=	security
MASTER_SITES=	http://www.validns.net/download/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.validns.net/
COMMENT=	Validns, a high performance DNS/DNSSEC zone validator
LICENSE=	2-clause-bsd

#BUILD_DEPENDS+=	p5-Test-Command-Simple-[0-9]*:../../devel/p5-Test-Command-Simple

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=perl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

#post-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/validns ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/validns.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
