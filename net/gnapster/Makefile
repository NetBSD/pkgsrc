# $NetBSD: Makefile,v 1.37 2004/12/28 23:18:16 reed Exp $

DISTNAME=	gnapster-1.5.0
PKGREVISION=	12
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
