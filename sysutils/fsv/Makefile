# $NetBSD: Makefile,v 1.1.1.1 2004/07/06 15:03:13 xtraeme Exp $
#

DISTNAME=	fsv-0.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fsv/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fsv.sourceforge.net/
COMMENT=	3D filesystem visualizer

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
