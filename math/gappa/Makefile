# $NetBSD: Makefile,v 1.1 2020/05/19 21:42:29 riastradh Exp $

DISTNAME=	gappa-1.3.5
CATEGORIES=	math
MASTER_SITES=	https://gforge.inria.fr/frs/download.php/file/38044/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gappa.gforge.inria.fr/
COMMENT=	Formal verification tool for numerical programs
LICENSE=	cecill-2.0 OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++

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
