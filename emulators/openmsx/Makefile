# $NetBSD: Makefile,v 1.51 2019/04/26 13:13:56 maya Exp $

DISTNAME=		openmsx-0.14.0
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_GITHUB:=openMSX/}
GITHUB_PROJECT=		openMSX
GITHUB_RELEASE=		RELEASE_0_14_0

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://openmsx.org/
COMMENT=		MSX emulator that aims for perfection
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c++03
HAS_CONFIGURE=		yes

MAKE_FILE=		GNUmakefile
MAKE_ENV+=		OPENMSX_FLAVOUR=opt
CONFIGURE_ENV+= 	OPENMSX_FLAVOUR=opt
CONFIGURE_ENV+= 	LOCALBASE=${PREFIX}
INSTALLATION_DIRS+=	bin
INSTALL_MAKE_FLAGS+=	SYMLINK_FOR_BINARY=false
INSTALL_MAKE_FLAGS+=	INSTALL_BASE=${PREFIX}/openmsx
MAKE_ENV+=		OPENMSX_INSTALL=${PREFIX}/openmsx

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 0.9.0

SUBST_CLASSES+=			bswap
SUBST_STAGE.bswap=		pre-configure
SUBST_MESSAGE.bswap=		Do not conflict bswap functions.
SUBST_FILES.bswap=		src/utils/endian.hh
SUBST_FILES.bswap+=		src/utils/tiger.cc
SUBST_SED.bswap=		-e 's, bswap, openmsx_bswap,g'
SUBST_SED.bswap+=		-e 's,::bswap,::openmsx_bswap,g'

.include "../../mk/bsd.prefs.mk"

.if "${PKGSRC_COMPILER}" == "clang"
# As a result of predefining CXX, .wrapper/bin/clang++ is automatically
# hardlinked to c++, g++, which is exactly what we what!
CXX=clang++
.elif "${PKGSRC_COMPILER}" == "gcc"
CXX=g++
.endif

post-extract:
	${CP} ${WRKSRC}/build/platform-freebsd.mk \
	      ${WRKSRC}/build/platform-dragonfly.mk

post-build:
	(							\
	${ECHO} "#!${SH}";					\
	${ECHO} 'exec ${PREFIX}/openmsx/bin/openmsx $$@'	\
	) > ${WRKSRC}/openmsx.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/openmsx.sh ${DESTDIR}${PREFIX}/bin/openmsx
	@${ECHO_MSG} "======================================================================"
	@${ECHO_MSG} "  Don't forget to have sound driver loaded before running openMSX."
	@${ECHO_MSG} "  Otherwise, aRts will throw an exception when launching OpenMSX or"
	@${ECHO_MSG} "  fail to create a directory called '.mcoprc' in the home directory."
	@${ECHO_MSG} "  However, you may execute OpenMSX without sound support like this:"
	@${ECHO_MSG} "  # env SDL_AUDIODRIVER=dummy openmsx <args>"
	@${ECHO_MSG} "======================================================================"

.include "../../audio/libao/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
