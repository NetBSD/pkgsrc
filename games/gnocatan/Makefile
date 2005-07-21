# $NetBSD: Makefile,v 1.32 2005/07/21 16:29:50 wiz Exp $
#

DISTNAME=	gnocatan-0.8.1.16
PKGREVISION=	4
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnocatan/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnocatan.sourceforge.net/
COMMENT=	GNOME version of the Settlers of Catan board game

GNU_CONFIGURE=		YES
USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
