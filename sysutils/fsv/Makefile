# $NetBSD: Makefile,v 1.7 2005/06/24 21:15:21 kristerw Exp $
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
CONFIGURE_ENV+=		FILE_CMD="${TOOLS_FILE_CMD}"

.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
