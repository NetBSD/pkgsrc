# $NetBSD: Makefile,v 1.1 2012/12/17 01:27:42 khorben Exp $
#

DISTNAME=	Editor-0.2.1
PKGNAME=	deforaos-editor-0.2.1
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
