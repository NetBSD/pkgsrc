# $NetBSD: Makefile,v 1.28 2012/10/02 17:10:56 tron Exp $
#

DISTNAME=	notecase-1.8.8_src
PKGNAME=	notecase-1.8.8
PKGREVISION=	15
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=notecase/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://notecase.sourceforge.net/
COMMENT=	Hierarchical note manager

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/notecase-1.8.8
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake msgfmt pkg-config gsed

LDFLAGS.DragonFly=	-lX11

INSTALLATION_DIRS=	share/doc/notecase share/locale/fr_CA/LC_MESSAGES \
			share/locale/no/LC_MESSAGES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../mk/bsd.pkg.mk"
