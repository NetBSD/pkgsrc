# $NetBSD: Makefile,v 1.21 2025/08/20 11:35:12 wiz Exp $

DISTNAME=	halibut-1.3
CATEGORIES=	textproc
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/halibut/halibut-${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/halibut/
COMMENT=	Documentation production system
LICENSE=	mit

USE_TOOLS+=	perl

INFO_FILES=	yes

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
