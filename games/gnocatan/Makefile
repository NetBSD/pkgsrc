# $NetBSD: Makefile,v 1.11 2003/07/13 13:59:36 wiz Exp $
#

DISTNAME=	gnocatan-0.7.1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnocatan/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://gnocatan.sourceforge.net/
COMMENT=	GNOME version of the Settlers of Catan board game

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
