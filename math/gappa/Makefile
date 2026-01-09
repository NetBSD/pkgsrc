# $NetBSD: Makefile,v 1.4 2026/01/09 20:30:29 alnsn Exp $

DISTNAME=	gappa-1.6.1
CATEGORIES=	math
MASTER_SITES=	https://gappa.gitlabpages.inria.fr/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gappa.gforge.inria.fr/
COMMENT=	Formal verification tool for numerical programs
LICENSE=	cecill-2.1 OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++

FORCE_CXX_STD+=		c++11
USE_CXX_FEATURES+=	c++11

do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ./remake -j${_MAKE_JOBS_N}

do-install:
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	./remake ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install

do-test:
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${TEST_ENV} \
	./remake ${MAKE_FLAGS} ${TEST_MAKE_FLAGS} check

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
