# $NetBSD: Makefile,v 1.11 2008/06/12 02:14:46 joerg Exp $
#

DISTNAME=	fsv-0.9
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fsv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fsv.sourceforge.net/
COMMENT=	3D filesystem visualizer

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		file gmake
CONFIGURE_ENV+=		FILE_CMD=${TOOLS_FILE_CMD:Q}

.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
