# $NetBSD: Makefile,v 1.9 2008/02/05 23:01:59 heinz Exp $
#

BOOST_PACKAGE=		python
BOOST_COMMENT=		(Boost.Python binary library)
BOOST_CONFIG=		installed

PKG_DESTDIR_SUPPORT=	user-destdir

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
