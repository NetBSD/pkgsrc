# $NetBSD: Makefile,v 1.1 2018/07/27 06:49:25 minskim Exp $

DISTNAME=	stan-math-2.17.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=stan-dev/}
GITHUB_PROJECT=	math
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mc-stan.org/
COMMENT=	Stan Math library
LICENSE=	modified-bsd

DEPENDS+=	boost-headers>=1.66.0:../../devel/boost-headers
DEPENDS+=	eigen3>=3.3.3:../../math/eigen3
DEPENDS+=	sundials>=3.1.1:../../math/sundials

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	include/stan

do-install:
	cd ${WRKSRC} && pax -rw stan ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
