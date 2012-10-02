# $NetBSD: Makefile,v 1.13 2012/10/02 17:11:41 tron Exp $
#

DISTNAME=	kdenlive-0.7.8
PKGREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.sourceforge.net/project/kdenlive/kdenlive/0.7.8/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.kdenlive.org/
COMMENT=	KDE video editor
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4
DEPENDS+=	dvdauthor>=0.6.18:../../multimedia/dvdauthor

PKG_DESTDIR_SUPPORT=	user-destdir

# INSTALL_UNSTRIPPED=no
# LDFLAGS=-g
# CFLAGS+=-g
# CXXFLAGS+=-g

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgfmt pkg-config

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../multimedia/mlt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
