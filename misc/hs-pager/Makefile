# $NetBSD: Makefile,v 1.7 2025/03/05 03:39:45 pho Exp $

DISTNAME=	pager-0.1.1.0
PKGREVISION=	4
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
