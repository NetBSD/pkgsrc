# $NetBSD: Makefile,v 1.13 2003/12/14 17:44:32 wiz Exp $
#

DISTNAME=	gnocatan-0.8.0.0
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnocatan/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnocatan.sourceforge.net/
COMMENT=	GNOME version of the Settlers of Catan board game

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
