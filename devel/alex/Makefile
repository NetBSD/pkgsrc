# $NetBSD: Makefile,v 1.1 2015/02/14 09:01:33 pho Exp $

DISTNAME=	alex-3.1.4
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Tool for generating lexical analysers in Haskell
LICENSE=	modified-bsd

USE_TOOLS+=	autoconf

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

pre-configure:
	cd ${WRKSRC}/doc && autoconf && ./configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/alex.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/haskell.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
