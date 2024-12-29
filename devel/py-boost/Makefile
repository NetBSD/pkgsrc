# $NetBSD: Makefile,v 1.24 2024/12/29 14:53:13 adam Exp $

BOOST_PACKAGE=		python
BOOST_COMMENT=		(Boost.Python binary library)
BOOST_CONFIG=		installed

INSTALLATION_DIRS+=	lib

.include "../../meta-pkgs/boost/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-boost-${BOOST_VERSION}

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

do-install: boost-install-libs

PLIST_SUBST+=	PYVER=${_PYTHON_VERSION}

BUILDLINK_TRANSFORM.SunOS+=	rm:-lutil

# These are already in boost-libs
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/libboost_*container.*
	${RM} -f ${DESTDIR}${PREFIX}/lib/libboost_*graph.*

.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
