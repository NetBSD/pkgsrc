# $NetBSD: Makefile,v 1.1 2024/05/05 05:28:36 pho Exp $

DISTNAME=	colourista-0.1.0.2
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
