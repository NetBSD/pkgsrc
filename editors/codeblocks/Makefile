# $NetBSD: Makefile,v 1.22 2022/08/15 20:40:11 he Exp $
#

DISTNAME=	codeblocks-20.03
PKGREVISION=	4
CATEGORIES=	editors x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=codeblocks/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.codeblocks.org/
COMMENT=	Open source, cross platform, free C++ IDE
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++11

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:M*gcc*)
CONFIGURE_ARGS+=	--disable-pch
.endif

#CONFIGURE_ARGS+=	--disable-gtk-notebook
CONFIGURE_ARGS+=	--with-contrib-plugins=AutoVersioning,BrowseTracker,-MouseSap,byogames,cbkoders,codesnippets,codestat,dragscroll,envvars,help,keybinder,libfinder,profiler,regex,exporter,symtab
# wxsmith makes error in build process

CXXFLAGS.Linux+=	-std=c++11

BUILD_DEPENDS+=	zip-[0-9]*:../../archivers/zip

PKGCONFIG_OVERRIDE+=	codeblocks.pc.in

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
