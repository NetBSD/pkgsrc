# $NetBSD: Makefile,v 1.16 2000/03/21 22:40:52 tron Exp $
#

DISTNAME=	freeciv-1.9.0
CATEGORIES=	games
MASTER_SITES=	http://www.freeciv.org/ftp/stable_version/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jonb@netbsd.org
HOMEPAGE=	http://www.freeciv.org/

DEPENDS+=	xpm-*:../../graphics/xpm
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=	jpeg-*:../../graphics/jpeg
DEPENDS+=	gettext-0.10.*:../../devel/gettext

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
