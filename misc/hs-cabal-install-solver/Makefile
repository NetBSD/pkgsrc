# $NetBSD: Makefile,v 1.5 2023/11/02 06:37:15 pho Exp $

DISTNAME=	cabal-install-solver-3.10.1.0
PKGREVISION=	1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Solver component used in cabal-install command-line program
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	base

.include "../../textproc/hs-edit-distance/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
