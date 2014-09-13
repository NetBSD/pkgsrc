# $NetBSD: Makefile,v 1.3 2014/09/13 22:23:28 szptvlfn Exp $

DISTNAME=		cpphs-1.18.5
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
