# $NetBSD: Makefile,v 1.29 2010/06/13 22:45:23 wiz Exp $
#

DISTNAME=	krusader-1.90.0
PKGREVISION=	6
CATEGORIES=	kde sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=krusader/}

MAINTAINER=	ianzag@mail.ru
HOMEPAGE=	http://krusader.sourceforge.net/
COMMENT=	Advanced twin-panel (commander-style) file-manager for KDE 3.x

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake perl msgfmt
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

SHLIBTOOL_OVERRIDE=	# empty

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+= --without-acl
.endif

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
