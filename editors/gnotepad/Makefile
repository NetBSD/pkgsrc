# $NetBSD: Makefile,v 1.4 2001/03/27 03:19:54 hubertf Exp $

DISTNAME=	gnotepad+-1.3.2
PKGNAME=	${DISTNAME:S/+//}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnotepad/}

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://gnotepad.sourceforge.net/
COMMENT=	easy-to-use, yet fairly feature-rich, simple HTML and text editor for X11

DEPENDS+=	gnome-core-*:../../x11/gnome-core
BUILD_USES_MSGFMT=	yes

USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=	# defined

.include "../../mk/bsd.pkg.mk"
