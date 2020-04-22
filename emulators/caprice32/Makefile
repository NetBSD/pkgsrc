# $NetBSD: Makefile,v 1.2 2020/04/22 08:13:39 nia Exp $

DISTNAME=	caprice32-4.6.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=ColinPitrat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ColinPitrat/caprice32
COMMENT=	Emulator of the Amstrad CPC 8bit home computer range
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++
MAKE_FILE=	makefile

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	GIT_HASH="pkgsrc"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Fix paths.
SUBST_FILES.conf+=	cap32.cfg
SUBST_FILES.conf+=	src/cap32.cfg
SUBST_FILES.conf+=	src/cap32.cpp
SUBST_FILES.conf+=	doc/man6/cap32.6
SUBST_VARS.conf+=	PREFIX
SUBST_VARS.conf+=	PKG_SYSCONFDIR

EGDIR=		${PREFIX}/share/examples/caprice32

CONF_FILES+=	${EGDIR}/cap32.cfg ${PKG_SYSCONFDIR}/cap32.cfg

RESTRICTED=	Questionable ROM images in source tree
NO_SRC_ON_FTP=	${RESTRICTED}

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
