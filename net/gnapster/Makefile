# $NetBSD: Makefile,v 1.34 2004/04/26 22:34:17 snj Exp $

DISTNAME=	gnapster-1.5.0
PKGREVISION=	9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnapster/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/gnapster/
COMMENT=	Simple client for the online mp3 community

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_X11=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
