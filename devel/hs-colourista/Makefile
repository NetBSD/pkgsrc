# $NetBSD: Makefile,v 1.3 2025/02/02 13:05:01 pho Exp $

DISTNAME=	colourista-0.1.0.2
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convenient interface for printing colourful messages
LICENSE=	mpl-2.0

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ansi-terminal	\
	base		\
	bytestring	\
	text

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
