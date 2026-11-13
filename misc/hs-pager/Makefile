# $NetBSD: Makefile,v 1.9 2026/11/13 14:39:37 pho Exp $

DISTNAME=	pager-0.1.1.0
PKGREVISION=	6
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Open up a pager, like 'less' or 'more'
LICENSE=	2-clause-bsd

HASKELL_DISABLE_EXECUTABLES+=	\
	hs-pager-test-pager

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
