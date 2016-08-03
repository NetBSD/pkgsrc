# $NetBSD: Makefile,v 1.3 2016/08/03 10:23:14 adam Exp $
#

DISTNAME=	VNCViewer-0.0.0
PKGNAME=	deforaos-vncviewer-0.0.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.defora.org/os/download/download/4407/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
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
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
