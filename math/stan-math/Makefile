# $NetBSD: Makefile,v 1.2 2019/03/10 02:33:05 wen Exp $

DISTNAME=	stan-math-2.18.1
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
DEPENDS+=	sundials>=4.1.0:../../math/sundials

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	include/stan

do-install:
	cd ${WRKSRC} && pax -rw stan ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
