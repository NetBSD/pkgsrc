# $NetBSD: Makefile,v 1.20 2004/10/03 00:12:54 tv Exp $
#

DISTNAME=       spruce-0.5.17
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spruce/}

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://spruce.sourceforge.net/
COMMENT=	MIME-aware, GNOME-based email program

USE_X11=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
