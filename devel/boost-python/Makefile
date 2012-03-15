# $NetBSD: Makefile,v 1.20 2012/03/15 11:53:23 obache Exp $

BOOST_PACKAGE=		python
PKGREVISION=		1
BOOST_COMMENT=		(Boost.Python binary library)
BOOST_CONFIG=		installed

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--user-config=${WRKSRC}/user-config.jam
BJAM_ARGS+=		--with-python
MAKE_ENV+=		BOOST_BUILD_PATH=${WRKSRC}
PYTHON_VERSIONS_ACCEPTED=	27 27 26 25

.include "../../devel/boost-jam/bjam.mk"
.include "../../lang/python/application.mk"

post-configure:
	${ECHO} 'using python : ${PYVERSSUFFIX} :' \
	    '${PREFIX}/bin/python${PYVERSSUFFIX} ;' \
	    >${WRKSRC}/user-config.jam

do-build: bjam-build

do-install: boost-install-libs

.include "../../mk/bsd.pkg.mk"
