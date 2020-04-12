# $NetBSD: Makefile,v 1.51 2020/04/12 19:44:55 joerg Exp $

DISTNAME=	FSViewer.app-0.2.5
PKGNAME=	FSViewer-0.2.5
PKGREVISION=	19
CATEGORIES=	sysutils x11 windowmaker
#MASTER_SITES=	#http://www.bayernline.de/~gscholz/linux/fsviewer/

#PATCH_SITES=		#http://www.bayernline.de/~gscholz/linux/fsviewer/
PATCHFILES=		FSViewer.app-0.2.5-WM-0.81.0.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	johnam@mail.kemper.org
#HOMEPAGE=	http://www.bayernline.de/~gscholz/linux/fsviewer/
COMMENT=	NextStep-like Filemanager for WindowMaker

USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

LDFLAGS.SunOS+=		-lWUtil -lX11 -lXpm -lintl -lm -lwraster
LDFLAGS.DragonFly=	-lintl -lfontconfig

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX:Q}/lib
.endif

.include "../../wm/windowmaker/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
