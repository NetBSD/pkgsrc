# $NetBSD: Makefile,v 1.15 2000/02/09 20:20:53 tron Exp $
#

DISTNAME=	freeciv-1.9.0
CATEGORIES=	games
MASTER_SITES=	http://www.freeciv.org/ftp/stable_version/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jonb@netbsd.org
HOMEPAGE=	http://www.freeciv.org/

DEPENDS+=	xpm-*:../../graphics/xpm
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	png>=1.0.3:../../graphics/png
DEPENDS+=	jpeg-*:../../graphics/jpeg
DEPENDS+=	gettext-0.10.*:../../devel/gettext

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
