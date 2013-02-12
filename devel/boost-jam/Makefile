# $NetBSD: Makefile,v 1.9 2013/02/12 21:07:21 adam Exp $

BOOST_PACKAGE=		jam
BOOST_COMMENT=		(Boost.Jam utility)
BOOST_CONFIG=		no

CONFLICTS+=		boost-build<=1.33.1

.include "../../meta-pkgs/boost/Makefile.common"

SUBST_CLASSES+=		bb
SUBST_MESSAGE.bb=	Fixing path to Boost.Build files.
SUBST_STAGE.bb=		pre-build
SUBST_FILES.bb=		tools/build/v2/engine/Jambase
SUBST_SED.bb=		-e 's,/usr/share/boost-build,${PREFIX}/share/boost-build,g'

.include "../../devel/boost-build/toolset.mk"

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/tools/build/v2/engine && \
		${SETENV} ${MAKE_ENV} ${SH} ./build.sh ${BOOST_TOOLSET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/build/v2/engine/bin.*/bjam \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
