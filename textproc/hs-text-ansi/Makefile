# $NetBSD: Makefile,v 1.4 2025/02/01 10:17:10 pho Exp $

DISTNAME=	text-ansi-0.3.0.1
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Text styling for ANSI terminals
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../textproc/hs-text-builder-linear/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
