# $NetBSD: Makefile,v 1.14 2024/05/09 01:32:13 pho Exp $

DISTNAME=	streaming-commons-0.2.2.6
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Common lower-level functions for various streaming data libraries
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	text

.include "../../devel/hs-async/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
