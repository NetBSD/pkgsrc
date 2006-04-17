# $NetBSD: Makefile,v 1.2 2006/04/17 13:46:09 wiz Exp $
#

DISTNAME=	libsexy-0.1.8
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	http://releases.chipx86.com/libsexy/libsexy/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.chipx86.com/wiki/Libsexy
COMMENT=	Collection of GTK+ widgets that beautify standard widgets

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

PKGCONFIG_OVERRIDE=	libsexy.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
