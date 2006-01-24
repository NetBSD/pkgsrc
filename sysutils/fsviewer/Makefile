# $NetBSD: Makefile,v 1.19 2006/01/24 07:32:34 wiz Exp $

DISTNAME=	FSViewer.app-0.2.5
PKGNAME=	FSViewer-0.2.5
PKGREVISION=	1
CATEGORIES=	sysutils x11 windowmaker
MASTER_SITES=	http://www.bayernline.de/~gscholz/linux/fsviewer/

PATCH_SITES=	http://www.bayernline.de/~gscholz/linux/fsviewer/
PATCHFILES=	FSViewer.app-0.2.5-WM-0.81.0.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.bayernline.de/~gscholz/linux/fsviewer/
COMMENT=	NextStep-like Filemanager for WindowMaker

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../wm/windowmaker/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
