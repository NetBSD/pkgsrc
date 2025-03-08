# $NetBSD: Makefile,v 1.1 2025/03/08 02:51:31 pho Exp $

DISTNAME=	io-streams-1.5.2.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple, composable, and easy-to-use stream I/O
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	bytestring	\
	network	\
	primitive	\
	text

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../archivers/hs-zlib-bindings/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
