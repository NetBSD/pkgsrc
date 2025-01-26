# $NetBSD: Makefile,v 1.26 2025/01/26 06:47:38 riastradh Exp $

BOOST_PACKAGE=		python
BOOST_COMMENT=		(Boost.Python binary library)
BOOST_CONFIG=		installed

INSTALLATION_DIRS+=	lib

.include "../../meta-pkgs/boost/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-boost-${BOOST_VERSION}
PKGREVISION=		1

BJAM_ARGS+=		--user-config=${WRKSRC}/user-config.jam
BJAM_ARGS+=		--with-python
MAKE_ENV+=		BOOST_BUILD_PATH=${WRKSRC}

.include "../../devel/boost-jam/bjam.mk"
.include "../../lang/python/pyversion.mk"

post-configure:
	${ECHO} 'using python : ${PYVERSSUFFIX} :' \
	    '${PREFIX}/bin/python${PYVERSSUFFIX} : ${PREFIX}/include/python${PYVERSSUFFIX} ;' \
	    >${WRKSRC}/user-config.jam

do-build: bjam-build

do-install: boost-install-cmake
do-install: boost-install-libs

PLIST_SUBST+=	PYVER=${_PYTHON_VERSION}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

BUILDLINK_TRANSFORM.SunOS+=	rm:-lutil

# These are already in boost-libs
#
# XXX Can we convince boost to simply not install these parts for this
# package?
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/Boost-*/*.cmake
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/BoostDetectToolset-*.cmake
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/boost_container-*/*.cmake
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/boost_graph-*/*.cmake
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/boost_headers-*/*.cmake
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/boost_numpy-*/*-config-version.cmake
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/boost_numpy-*/*-config.cmake
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/boost_python-*/*-config-version.cmake
	${RM} -f ${DESTDIR}${PREFIX}/lib/cmake/boost_python-*/*-config.cmake
	${RM} -f ${DESTDIR}${PREFIX}/lib/libboost_*container.*
	${RM} -f ${DESTDIR}${PREFIX}/lib/libboost_*graph.*

BUILDLINK_API_DEPENDS.boost-libs+=	boost-libs-${BOOST_VERSION}{,nb[0-9]*}
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/py-boost-cmake/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
