# $NetBSD: Makefile,v 1.1 2025/01/23 19:37:40 riastradh Exp $

BOOST_PACKAGE=		python
BOOST_COMMENT=		(Boost.Python cmake files)
BOOST_CONFIG=		installed

INSTALLATION_DIRS+=	lib

.include "../../meta-pkgs/boost/Makefile.common"

PKGNAME=		py-boost-cmake-${BOOST_VERSION}

# Note: This does NOT contain ${PYPKGPREFIX} -- it is
# Python-version-agnostic.  So we only build it with the default Python
# version -- or, as a hack if we're building this as a transitive
# dependency of another Python package that is being built with a
# specified non-default Python version, PYTHON_VERSION_REQD.

# XXX Can we convince bjam to build just the cmake files?
#
# XXX Reduce copypasta from devel/py-boost/Makefile.
.if !defined(PYTHON_VERSION_REQD)
PYTHON_VERSIONS_ACCEPTED=	${PYTHON_VERSION_DEFAULT}
.endif

USE_TOOLS+=		pax

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

do-install:
	@${STEP_MSG} Installing py-boost cmake files
	${RUN}cd ${WRKSRC}/stage/lib && \
	${FIND} cmake -name 'boost_python-config*.cmake' \
		-o -name 'boost_numpy-config*.cmake' \
	| ${PAX} -rw -p p ${DESTDIR}${PREFIX}/lib

BUILDLINK_TRANSFORM.SunOS+=	rm:-lutil

.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
