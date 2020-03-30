# $NetBSD: Makefile,v 1.1 2020/03/30 16:51:09 riastradh Exp $

DISTNAME=	tasty-1.2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=tasty-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/feuerbach/tasty
COMMENT=	Modern and extensible testing framework
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../devel/hs-optparse-applicative/buildlink3.mk"
.include "../../devel/hs-unbounded-delays/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../textproc/hs-wcwidth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
