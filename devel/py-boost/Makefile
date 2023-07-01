# $NetBSD: Makefile,v 1.21 2023/07/01 08:37:34 wiz Exp $

BOOST_PACKAGE=		python
BOOST_COMMENT=		(Boost.Python binary library)
BOOST_CONFIG=		installed

INSTALLATION_DIRS+=	lib

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

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

.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
