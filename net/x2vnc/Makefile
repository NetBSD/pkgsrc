# $NetBSD: Makefile,v 1.15 2007/01/16 13:30:59 abs Exp $
#

DISTNAME=       	x2vnc-1.7.2
CATEGORIES=		net x11
MASTER_SITES=   	http://fredrik.hubbe.net/x2vnc/

MAINTAINER=	 	pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fredrik.hubbe.net/x2vnc.html
COMMENT=		Multi-console display using X and VNC

GNU_CONFIGURE=		yes

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

