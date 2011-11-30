# $NetBSD: Makefile,v 1.14 2011/11/30 12:07:52 wiz Exp $

DISTNAME=	yabause-0.9.11
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yabause/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://yabause.sourceforge.net/
COMMENT=	Sega Saturn system emulator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

SUBST_CLASSES+=			pkgmandir
SUBST_STAGE.pkgmandir=		pre-configure
SUBST_FILES.pkgmandir=		src/gtk/CMakeLists.txt src/qt/CMakeLists.txt
SUBST_SED.pkgmandir=		-e "s,share/man,${PKGMANDIR},"
SUBST_MESSAGE.pkgmandir=	Fixing hardcoded manual paths.

.include "options.mk"

.include "../../graphics/glut/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
