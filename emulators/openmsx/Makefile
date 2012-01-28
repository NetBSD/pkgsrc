# $NetBSD: Makefile,v 1.28 2012/01/28 11:00:52 wiz Exp $
#

DISTNAME=		openmsx-0.6.2
PKGREVISION=		6
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=openmsx/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://openmsx.sourceforge.net/
COMMENT=		MSX emulator that aims for perfection

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
HAS_CONFIGURE=		yes

MAKE_FILE=		GNUmakefile
CONFIGURE_ENV+=		OPENMSX_FLAVOUR=pkgsrc
MAKE_ENV+=		OPENMSX_FLAVOUR=pkgsrc

post-extract:
	${CP} ${FILESDIR}/platform-netbsd.mk ${WRKSRC}/build
	${LN} -s platform-netbsd.mk ${WRKSRC}/build/platform-dragonfly.mk
	${ECHO_MSG} "OPENMSX_STRIP:=true" > \
		${WRKSRC}/build/flavour-pkgsrc.mk

REPLACE_PYTHON+=	share/scripts/convert_hardwareconfig.py
REPLACE_PYTHON+=	share/scripts/convert_hardwareconfig2.py

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	build/custom.mk
SUBST_SED.prefix=	-e "s,/opt/openMSX,${PREFIX}/openmsx,"
SUBST_MESSAGE.prefix=	Fixing installation directory.

post-build:
	(							\
	${ECHO} "#!${SH}";					\
	${ECHO} 'exec ${PREFIX}/openmsx/bin/openmsx $$@'	\
	) > ${WRKSRC}/openmsx.sh

INSTALLATION_DIRS+=	bin
INSTALL_MAKE_FLAGS+=	OPENMSX_INSTALL=${DESTDIR}${PREFIX}/openmsx

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/openmsx.sh ${DESTDIR}${PREFIX}/bin/openmsx

.include "../../lang/python/application.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
