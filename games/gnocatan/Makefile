# $NetBSD: Makefile,v 1.20 2004/02/09 18:47:37 jmmv Exp $
#

DISTNAME=	gnocatan-0.8.0.0
PKGREVISION=	5
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnocatan/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnocatan.sourceforge.net/
COMMENT=	GNOME version of the Settlers of Catan board game

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
