# $NetBSD: Makefile,v 1.3 2023/12/29 18:24:40 adam Exp $

BOOST_PACKAGE=		mpi
BOOST_COMMENT=		(Boost.MPI binary library)
BOOST_CONFIG=		installed

INSTALLATION_DIRS+=	lib

PKGREVISION= 1
.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--user-config=${WRKSRC}/user-config.jam
BJAM_ARGS+=		--with-mpi
MAKE_ENV+=		BOOST_BUILD_PATH=${WRKSRC}

.include "../../devel/boost-jam/bjam.mk"

post-configure:
	${ECHO} 'using mpi ;' >${WRKSRC}/user-config.jam

do-build: bjam-build

do-install: boost-install-libs

# boost_serialization already in boost-libs
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/libboost_*serialization.*

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
