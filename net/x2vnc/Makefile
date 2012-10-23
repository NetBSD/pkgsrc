# $NetBSD: Makefile,v 1.20 2012/10/23 17:19:20 asau Exp $
#

DISTNAME=		x2vnc-1.7.2
PKGREVISION=		1
CATEGORIES=		net x11
MASTER_SITES=		http://fredrik.hubbe.net/x2vnc/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fredrik.hubbe.net/x2vnc.html
COMMENT=		Multi-console display using X and VNC

GNU_CONFIGURE=		yes
LDFLAGS.SunOS+=		-lresolv

.include "options.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
