# $NetBSD: Makefile,v 1.2 2020/01/01 05:37:22 pho Exp $

DISTNAME=	happy-1.19.12
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Parser generator for Haskell
LICENSE=	modified-bsd

USE_TOOLS+=	autoconf

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

pre-configure:
	cd ${WRKSRC}/doc && autoconf && ./configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/happy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/haskell.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
