# $NetBSD: Makefile,v 1.5 2001/08/29 22:41:20 jlam Exp $

DISTNAME=	sylpheed-0.3.23
CATEGORIES=	mail x11
MASTER_SITES=	http://sylpheed.good-day.net/sylpheed/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://sylpheed.good-day.net/index.cgi.en
COMMENT=	X based e-mail client

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nls

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
