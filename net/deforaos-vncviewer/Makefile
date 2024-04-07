# $NetBSD: Makefile,v 1.35 2024/04/07 07:34:46 wiz Exp $
#

DISTNAME=	VNCViewer-0.1.0
PKGNAME=	deforaos-vncviewer-0.1.0
PKGREVISION=	19
CATEGORIES=	net
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/VNCViewer/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop VNC viewer

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

CONFLICTS=	tightvncviewer-[0-9]*
CONFLICTS+=	vncviewer-[0-9]*

.include "../../net/gtk-vnc/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
