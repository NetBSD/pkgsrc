# $NetBSD: Makefile,v 1.9 2001/09/27 23:18:03 jlam Exp $
#

DISTNAME=       gnofin-0.8.4
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnofin/}

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://gnofin.sourceforge.net/
COMMENT=	Personal checking/savings account management program

BUILD_USES_MSGFMT=	yes
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	gnome-libs-[0-9]*:../../x11/gnome-libs
DEPENDS+=	libxml>=1.8.10:../../textproc/libxml

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBINTL=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
