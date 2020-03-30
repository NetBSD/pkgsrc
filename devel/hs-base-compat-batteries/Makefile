# $NetBSD: Makefile,v 1.1 2020/03/30 16:33:17 riastradh Exp $

DISTNAME=	base-compat-batteries-0.11.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_HASKELL_HACKAGE:=base-compat-batteries-${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hackage.haskell.org/package/base-compat-batteries/
COMMENT=	Base library compatibility without cpp
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
