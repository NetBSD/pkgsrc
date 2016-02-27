# $NetBSD: Makefile,v 1.2 2016/02/27 20:55:05 wiz Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 # as of 1.58.0

.include "../../devel/boost-jam/bjam.mk"
.include "../../lang/python/application.mk"

post-configure:
	${ECHO} 'using python : ${PYVERSSUFFIX} :' \
	    '${PREFIX}/bin/python${PYVERSSUFFIX} ;' \
	    >${WRKSRC}/user-config.jam

do-build: bjam-build

do-install: boost-install-libs

.if ${PYPKGPREFIX} != py27
# The python3 variant also includes redundant copies of the libs
# that conflict with the python2 variant.
post-install:
	${RM} -v ${DESTDIR}${PREFIX}/lib/libboost_python.*
.endif

.include "../../mk/bsd.pkg.mk"
