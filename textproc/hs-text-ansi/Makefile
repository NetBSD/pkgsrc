# $NetBSD: Makefile,v 1.6 2025/03/05 03:40:04 pho Exp $

DISTNAME=	text-ansi-0.3.0.1
PKGREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Text styling for ANSI terminals
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../textproc/hs-text-builder-linear/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
