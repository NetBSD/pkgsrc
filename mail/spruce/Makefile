# $NetBSD: Makefile,v 1.2 2000/02/03 23:38:17 tron Exp $
#

DISTNAME=       spruce-0.5.14
CATEGORIES=	mail
MASTER_SITES=   http://www.xtorshun.org/spruce/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.xtorshun.org/spruce/main.html

DEPENDS+=	gnome-libs-*:../../x11/gnome-libs
DEPENDS+=	mit-pthreads-*:../../devel/mit-pthreads

USE_X11=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CC=		${LOCALBASE}/pthreads/bin/pgcc

.include "../../mk/bsd.pkg.mk"
