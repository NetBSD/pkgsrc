# $NetBSD: Makefile,v 1.8 2008/01/04 19:58:40 jmmv Exp $
#

BOOST_PACKAGE=		python
BOOST_COMMENT=		(Boost.Python binary library)
BOOST_CONFIG=		installed

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--with-python
MAKE_ENV+=		HOME=${WRKSRC}

.include "../../devel/boost-jam/bjam.mk"
.include "../../lang/python/application.mk"

post-configure:
	echo 'using python : ${PYVERSSUFFIX} :' \
	    '${PREFIX}/bin/python${PYVERSSUFFIX} ;' \
	    >${WRKSRC}/user-config.jam

do-build: bjam-build

do-install: boost-install-libs

.include "../../mk/bsd.pkg.mk"
