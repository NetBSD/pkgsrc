# $NetBSD: Makefile,v 1.8 2006/12/14 22:10:24 rillig Exp $

DISTNAME=	gpredict-0.6.1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://groundstation.sourceforge.net/
COMMENT=	Gnome satellite tracking program

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake msgfmt pkg-config
USE_PKGLOCALEDIR=yes
GNU_CONFIGURE=	yes

.include "../../devel/GConf/buildlink3.mk"
.include "../../graphics/gdk-pixbuf-gnome/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
#.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
