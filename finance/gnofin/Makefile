# $NetBSD: Makefile,v 1.5 2000/12/17 12:00:42 wiz Exp $
#

DISTNAME=       gnofin-0.8.4
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnofin/}

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://gnofin.sourceforge.net/

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	libxml>=1.8.10:../../textproc/libxml

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBINTL=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
