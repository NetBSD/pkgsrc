# $NetBSD: Makefile,v 1.12 2023/01/26 11:23:15 pho Exp $

DISTNAME=	conduit-1.3.4.3
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
