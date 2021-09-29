# $NetBSD: Makefile,v 1.16 2021/09/29 16:11:04 adam Exp $

BOOST_PACKAGE=		jam
BOOST_COMMENT=		(Boost.Jam utility)
BOOST_CONFIG=		no

CONFLICTS+=		boost-build<=1.33.1

.include "../../meta-pkgs/boost/Makefile.common"

SUBST_CLASSES+=		opt
SUBST_MESSAGE.opt=	Removing -O3 flag.
SUBST_STAGE.opt=	pre-build
SUBST_FILES.opt=	tools/build/src/engine/build.sh
SUBST_SED.opt=		-e 's,-O3,,g'

.include "../../devel/boost-build/toolset.mk"

INSTALLATION_DIRS=	bin

# Fix RELRO build
CXXFLAGS+=	${LDFLAGS}

do-build:
	cd ${WRKSRC}/tools/build/src/engine && \
		${SETENV} ${MAKE_ENV} ${SH} ./build.sh ${BOOST_TOOLSET} --cxxflags=${CXXFLAGS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/build/src/engine/b2 \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/build/src/engine/bjam \
		${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
