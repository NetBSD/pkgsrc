# $NetBSD: Makefile,v 1.13 1999/12/18 18:26:37 jonb Exp $
#

DISTNAME=	freeciv-1.9.0
CATEGORIES=	games
MASTER_SITES=	http://www.freeciv.org/ftp/stable_version/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jonb@netbsd.org
HOMEPAGE=	http://www.freeciv.org/

DEPENDS+=	xpm-*:../../graphics/xpm
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	png-*:../../graphics/png
DEPENDS+=	jpeg-*:../../graphics/jpeg
DEPENDS+=	gettext-*:../../devel/gettext

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
