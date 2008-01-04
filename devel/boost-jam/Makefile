# $NetBSD: Makefile,v 1.3 2008/01/04 19:58:40 jmmv Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

BOOST_PACKAGE=		jam
BOOST_COMMENT=		(Boost.Jam utility)
BOOST_CONFIG=		no

CONFLICTS+=		boost-build<=1.33.1

.include "../../meta-pkgs/boost/Makefile.common"

SUBST_CLASSES+=		bb
SUBST_MESSAGE.bb=	Fixing path to Boost.Build files.
SUBST_STAGE.bb=		pre-build
SUBST_FILES.bb=		tools/jam/src/Jambase
SUBST_SED.bb=		-e 's,/usr/share/boost-build,${PREFIX}/share/boost-build,g'

.include "../../devel/boost-build/toolset.mk"

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/tools/jam/src && \
	    ${SETENV} ${MAKE_ENV} ${SH} ./build.sh ${BOOST_TOOLSET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/jam/src/bin.*/bjam \
	    ${DESTDIR:Q}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
