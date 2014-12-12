# $NetBSD: Makefile,v 1.6 2014/12/12 22:55:24 szptvlfn Exp $

DISTNAME=		cpphs-1.18.6
PKGREVISION=		2
CATEGORIES=		devel

MAINTAINER=		esg@sdf.lonestar.org
COMMENT=		Re-implementation of cpp in Haskell
LICENSE=		gnu-lgpl-v2.1

INSTALLATION_DIRS+= ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/cpphs.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/haskell.mk"
.include "../../textproc/hs-polyparse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
