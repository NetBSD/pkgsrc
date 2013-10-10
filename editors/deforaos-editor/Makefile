# $NetBSD: Makefile,v 1.7 2013/10/10 14:42:06 ryoon Exp $
#

DISTNAME=	Editor-0.2.1
PKGNAME=	deforaos-editor-0.2.1
PKGREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	http://www.defora.org/os/download/download/3702/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop text editor

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
