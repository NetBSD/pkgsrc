# $NetBSD: Makefile,v 1.7 2000/08/03 23:52:03 jlam Exp $
# FreeBSD Id: Makefile,v 1.7 1998/12/09 06:59:39 vanilla Exp
#

DISTNAME=	gqview-0.8.2
CATEGORIES=	graphics x11
MASTER_SITES=	http://download.sourceforge.net/gqview/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://gqview.sourceforge.net/index.html

DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_GNOME_CONFIG=no
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

# for libintl detection in configure script
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
