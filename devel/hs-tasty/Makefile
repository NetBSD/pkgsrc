# $NetBSD: Makefile,v 1.2 2020/04/03 07:30:53 wiz Exp $

DISTNAME=	tasty-1.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=tasty-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/feuerbach/tasty
COMMENT=	Modern and extensible testing framework
LICENSE=	mit

DEPENDS+=	hs-async-[0-9]*:../../devel/hs-async
DEPENDS+=	hs-tagged-[0-9]*:../../devel/hs-tagged

USE_LANGUAGES=	# none

.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-unbounded-delays/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../textproc/hs-wcwidth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
