# $NetBSD: Makefile,v 1.1.1.1 2000/12/13 01:14:51 wiz Exp $

DISTNAME=	gnotepad-1.3.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnotepad/}

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://gnotepad.sourceforge.net/

DEPENDS+=	gnome-core-*:../../x11/gnome-core
BUILD_DEPENDS+=	msgfmt:../../devel/gettext

USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=	# defined

.include "../../mk/bsd.pkg.mk"
