# $NetBSD: Makefile,v 1.18 2004/01/24 13:55:30 grant Exp $
#

DISTNAME=       spruce-0.5.17
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spruce/}

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://spruce.sourceforge.net/
COMMENT=	MIME-aware, GNOME-based email program

USE_X11=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
