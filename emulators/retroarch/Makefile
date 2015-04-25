# $NetBSD: Makefile,v 1.6 2015/04/25 14:20:47 tnn Exp $

DISTNAME=	retroarch-20150203
PKGNAME=	retroarch-0.0.20150203
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/retroarch/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libretro.com/
COMMENT=	Official reference frontend for the libretro API
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/RetroArch-master
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--global-config-dir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+= MAN_DIR=${PREFIX}/${PKGMANDIR}/man1/
CONFIG_SHELL=	bash
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash pkg-config gmake

PYTHON_VERSIONS_INCOMPATIBLE=	27
REPLACE_PYTHON=	tools/cg2glsl.py

EGDIR=		${PREFIX}/share/examples/retroarch
CONF_FILES+=	${EGDIR}/retroarch.cfg ${PKG_SYSCONFDIR}/retroarch.cfg

SUBST_CLASSES+=		qb
SUBST_STAGE.qb=		pre-configure
SUBST_MESSAGE.qb=	Fixing path to true(1) in configure scripts.
SUBST_FILES.qb=		qb/qb.libs.sh
SUBST_SED.qb+=		-e 's;/bin/true;${TRUE};'

SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		qb/config.libs.sh
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'

SUBST_CLASSES+=		cfg
SUBST_STAGE.cfg=	pre-configure
SUBST_MESSAGE.cfg=	Setting paths in sample config.
SUBST_FILES.cfg=	retroarch.cfg
SUBST_SED.cfg+=		-e 's;.*libretro_directory =.*;libretro_directory = "${PREFIX}/lib/libretro";'

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/retroarch-joyconfig \
	    ${DESTDIR}${PREFIX}/bin/retroarch-joyconfig

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
#.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
