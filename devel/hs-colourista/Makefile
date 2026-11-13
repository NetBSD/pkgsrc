# $NetBSD: Makefile,v 1.6 2026/11/13 14:38:52 pho Exp $

DISTNAME=	colourista-0.1.0.2
PKGREVISION=	5
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
