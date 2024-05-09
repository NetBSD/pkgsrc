# $NetBSD: Makefile,v 1.13 2024/05/09 01:32:01 pho Exp $

DISTNAME=	libffi-0.2.1
PKGREVISION=	4
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
