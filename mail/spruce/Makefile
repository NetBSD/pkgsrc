# $NetBSD: Makefile,v 1.3 2000/02/04 00:13:21 tron Exp $
#

DISTNAME=       spruce-0.5.14
CATEGORIES=	mail
MASTER_SITES=   http://www.xtorshun.org/spruce/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.xtorshun.org/spruce/main.html

DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	ptl2-*:../../devel/ptl2

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CC=		${LOCALBASE}/bin/ptlgcc

.include "../../mk/bsd.pkg.mk"
