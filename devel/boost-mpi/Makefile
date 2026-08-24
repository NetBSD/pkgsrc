# $NetBSD: Makefile,v 1.8 2026/08/24 07:41:50 adam Exp $

BOOST_PACKAGE=		mpi
BOOST_COMMENT=		(Boost.MPI binary library)
BOOST_CONFIG=		installed

INSTALLATION_DIRS+=	lib

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--user-config=${WRKSRC}/user-config.jam
BJAM_ARGS+=		--with-mpi
MAKE_ENV+=		BOOST_BUILD_PATH=${WRKSRC}

.include "../../devel/boost-jam/bjam.mk"

post-configure:
	${ECHO} 'using mpi ;' >${WRKSRC}/user-config.jam

do-build: bjam-build

do-install: boost-install-libs

# These are already in boost-libs
post-install:
.for libname in atomic chrono container date_time exception graph math math_c99 math_c99f \
                math_c99l math_tr1 math_tr1f math_tr1l random serialization thread
	${RM} -f ${DESTDIR}${PREFIX}/lib/libboost_*${libname}.*
.endfor

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
