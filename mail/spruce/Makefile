# $NetBSD: Makefile,v 1.12 2002/07/17 11:22:38 agc Exp $
#

DISTNAME=       spruce-0.5.17
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spruce/}

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://spruce.sourceforge.net/
COMMENT=	MIME-aware, GNOME-based email program

DEPENDS+=	gnome-libs>=1.4.1.2nb1:../../x11/gnome-libs

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAKE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

.include "../../mk/bsd.pkg.mk"
