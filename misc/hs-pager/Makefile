# $NetBSD: Makefile,v 1.1 2023/10/31 15:33:10 pho Exp $

DISTNAME=	pager-0.1.1.0
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Open up a pager, like 'less' or 'more'
LICENSE=	2-clause-bsd

# Don't build or install an example program.
SUBST_CLASSES+=		example
SUBST_STAGE.example=	post-extract
SUBST_FILES.example=	pager.cabal
SUBST_SED.example=	-e '/^executable hs-pager-test-pager$$/a\${.newline}  buildable: False'

.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
