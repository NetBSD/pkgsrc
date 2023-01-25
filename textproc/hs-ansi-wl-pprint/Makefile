# $NetBSD: Makefile,v 1.7 2023/01/25 14:03:57 pho Exp $

DISTNAME=	ansi-wl-pprint-0.6.9
PKGREVISION=	5
CATEGORIES=	textproc

MAINTAINER=	pho@cielonegro.org
COMMENT=	Wadler/Leijen Pretty Printer for colored ANSI terminal output
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	ansi-terminal

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
