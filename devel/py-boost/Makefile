# $NetBSD: Makefile,v 1.10 2018/11/13 12:00:33 markd Exp $

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

.if exists(${PYTHONBIN}m)
M=	m
.else
M=
.endif

post-configure:
	${ECHO} 'using python : ${PYVERSSUFFIX} :' \
	    '${PREFIX}/bin/python${PYVERSSUFFIX} : ${PREFIX}/include/python${PYVERSSUFFIX}${M} ;' \
	    >${WRKSRC}/user-config.jam

do-build: bjam-build

do-install: boost-install-libs

PLIST_SUBST+=	PYVER=${_PYTHON_VERSION}

#.if ${PYPKGPREFIX} != py27
# The python3 variant also includes redundant copies of the libs
# that conflict with the python2 variant.
#post-install:
#	${RM} -f ${DESTDIR}${PREFIX}/lib/libboost_python.*
#.endif

.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
