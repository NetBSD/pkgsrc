# $NetBSD: Makefile,v 1.41 2014/05/09 07:37:04 wiz Exp $

DISTNAME=		openmsx-0.9.0
PKGREVISION=		4
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openmsx/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://openmsx.sourceforge.net/
COMMENT=		MSX emulator that aims for perfection
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c++
HAS_CONFIGURE=		yes

MAKE_FILE=		GNUmakefile
MAKE_ENV+=		OPENMSX_FLAVOUR=opt
CONFIGURE_ENV+= 	OPENMSX_FLAVOUR=opt
CONFIGURE_ENV+= 	LOCALBASE=${PREFIX}
INSTALLATION_DIRS+=	bin
INSTALL_MAKE_FLAGS+=	SYMLINK_FOR_BINARY=false
INSTALL_MAKE_FLAGS+=	INSTALL_BASE=${PREFIX}/openmsx
MAKE_ENV+=		OPENMSX_INSTALL=${PREFIX}/openmsx

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.9.0

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
	# Fix permission problem specific to release 0.9.0 and below
	${CHMOD} 644 ${WRKSRC}/share/extensions/debugdevice/hardwareconfig.xml
	${CHMOD} 644 ${WRKSRC}/share/extensions/gfx9000/hardwareconfig.xml

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
