# $NetBSD: Makefile,v 1.1.1.1 2006/01/15 13:05:39 wulf Exp $

DISTNAME=	gpredict-0.5.2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=       http://groundstation.sourceforge.net/
COMMENT=	Gnome satellite tracking program

USE_TOOLS+=	gmake pkg-config
USE_PKGLOCALEDIR=yes
GNU_CONFIGURE=	yes
BUILD_USES_MSGFMT=yes

.include "../../devel/GConf/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
