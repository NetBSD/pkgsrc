# $NetBSD: Makefile,v 1.2 2001/02/17 18:25:07 wiz Exp $

DISTNAME=	sylpheed-0.3.23
CATEGORIES=	mail x11
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://sylpheed.good-day.net/index.cgi.en
COMMENT=	an X based e-mail client

DEPENDS+=	gtk+>=1.2.6:../../x11/gtk

USE_GMAKE=	yes
USE_X11=	yes
USE_X11BASE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${X11BASE} \
		--includedir=${LOCALBASE}/include \
		--libdir=${LOCALBASE}/lib \
		--enable-nls

.include "../../mk/bsd.pkg.mk"
