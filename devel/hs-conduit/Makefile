# $NetBSD: Makefile,v 1.13 2023/02/07 01:40:30 pho Exp $

DISTNAME=	conduit-1.3.4.3
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Streaming data processing library
LICENSE=	mit

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	resourcet

.include "../../mk/haskell.mk"
.include "../../devel/hs-mono-traversable/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
