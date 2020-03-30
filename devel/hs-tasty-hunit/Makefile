# $NetBSD: Makefile,v 1.1 2020/03/30 16:51:43 riastradh Exp $

DISTNAME=	tasty-hunit-0.10.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=tasty-hunit-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/feuerbach/tasty
COMMENT=	HUnit support for the Tasty test framework
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
