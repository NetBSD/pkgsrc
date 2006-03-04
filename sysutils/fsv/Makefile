# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:41 jlam Exp $
#

DISTNAME=	fsv-0.9
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fsv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fsv.sourceforge.net/
COMMENT=	3D filesystem visualizer

GNU_CONFIGURE=		yes
USE_TOOLS+=		file gmake
CONFIGURE_ENV+=		FILE_CMD=${TOOLS_FILE_CMD:Q}

.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
