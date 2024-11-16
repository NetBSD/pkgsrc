# $NetBSD: Makefile,v 1.20 2024/11/16 08:48:47 wiz Exp $

DISTNAME=	halibut-1.3
CATEGORIES=	textproc
MASTER_SITES=	https://www.chiark.greenend.org.uk/~sgtatham/halibut/halibut-${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.chiark.greenend.org.uk/~sgtatham/halibut/
COMMENT=	Documentation production system
LICENSE=	mit

USE_TOOLS+=	perl

INFO_FILES=	yes

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
