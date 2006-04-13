# $NetBSD: Makefile,v 1.4 2006/04/13 18:23:34 jlam Exp $

DISTNAME=	gpredict-0.5.2
PKGREVISION=	2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=       http://groundstation.sourceforge.net/
COMMENT=	Gnome satellite tracking program

USE_TOOLS+=	gmake msgfmt pkg-config
USE_PKGLOCALEDIR=yes
GNU_CONFIGURE=	yes

.include "../../devel/GConf/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
