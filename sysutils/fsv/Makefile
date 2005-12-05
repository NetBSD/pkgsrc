# $NetBSD: Makefile,v 1.8 2005/12/05 20:51:00 rillig Exp $
#

DISTNAME=	fsv-0.9
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fsv/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fsv.sourceforge.net/
COMMENT=	3D filesystem visualizer

GNU_CONFIGURE=		yes
USE_TOOLS+=		file gmake
CONFIGURE_ENV+=		FILE_CMD=${TOOLS_FILE_CMD:Q}

.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
