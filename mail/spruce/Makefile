# $NetBSD: Makefile,v 1.13 2002/12/01 15:38:00 salo Exp $
#

DISTNAME=       spruce-0.5.17
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spruce/}

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://spruce.sourceforge.net/
COMMENT=	MIME-aware, GNOME-based email program

DEPENDS+=	gnome-libs>=1.4.1.2nb1:../../x11/gnome-libs

USE_X11=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

.include "../../mk/bsd.pkg.mk"
