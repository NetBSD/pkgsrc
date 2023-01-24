# $NetBSD: Makefile,v 1.9 2023/01/24 16:52:29 pho Exp $

DISTNAME=	libffi-0.2.1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
COMMENT=	Haskell binding to libffi
LICENSE=	modified-bsd

# Our GHC is built with a system libffi. See ${WRKSRC}/README.md for
# details.
USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	-f-ghc-bundled-libffi

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
