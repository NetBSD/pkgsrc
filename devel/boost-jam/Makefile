# $NetBSD: Makefile,v 1.2 2007/11/29 22:27:13 heinz Exp $
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
SUBST_FILES.bb=		tools/build/jam_src/Jambase
SUBST_SED.bb=		-e 's,/usr/share/boost-build,${PREFIX}/share/boost-build,g'

.include "../../devel/boost-build/toolset.mk"

INSTALLATION_DIRS=	bin

pre-build:
	rm ${WRKSRC}/tools/build/jam_src/jambase.c

do-build:
	cd ${WRKSRC}/tools/build/jam_src && \
	    ${SETENV} ${MAKE_ENV} ${SH} ./build.sh ${BOOST_TOOLSET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/build/jam_src/bin.*/bjam \
	    ${DESTDIR:Q}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
