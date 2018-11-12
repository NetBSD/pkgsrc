# $NetBSD: Makefile,v 1.36 2018/11/12 03:51:13 ryoon Exp $
#

DISTNAME=	libsexy-0.1.11
PKGREVISION=	28
CATEGORIES=	devel gnome
MASTER_SITES=	http://releases.chipx86.com/libsexy/libsexy/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.chipx86.com/wiki/Libsexy
COMMENT=	Collection of GTK+ widgets that beautify standard widgets

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	libsexy.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
