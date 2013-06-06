# $NetBSD: Makefile,v 1.5 2013/06/06 12:54:15 wiz Exp $
#

DISTNAME=	Editor-0.2.1
PKGNAME=	deforaos-editor-0.2.1
PKGREVISION=	4
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
