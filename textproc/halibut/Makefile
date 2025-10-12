# $NetBSD: Makefile,v 1.22 2025/10/12 21:12:51 nia Exp $

DISTNAME=	halibut-1.3
CATEGORIES=	textproc
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/halibut/halibut-${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/halibut/
COMMENT=	Documentation production system
LICENSE=	mit

USE_TOOLS+=	perl

INFO_FILES=	yes

FORCE_C_STD=	gnu99

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
