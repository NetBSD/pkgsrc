# $NetBSD: Makefile,v 1.6 2000/07/31 04:14:08 jlam Exp $
# FreeBSD Id: Makefile,v 1.7 1998/12/09 06:59:39 vanilla Exp
#

DISTNAME=	gqview-0.8.1
CATEGORIES=	graphics x11
MASTER_SITES=	http://download.sourceforge.net/gqview/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://gqview.sourceforge.net/index.html

DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
# for libintl detection in configure script
CFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
