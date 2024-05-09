# $NetBSD: Makefile,v 1.10 2024/05/09 01:31:57 pho Exp $

DISTNAME=	githash-0.1.7.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Compile git revision info into Haskell projects
LICENSE=	modified-bsd

DEPENDS+=	git-[0-9]*:../../devel/git-base

.include "../../devel/hs-th-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
