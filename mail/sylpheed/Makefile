# $NetBSD: Makefile,v 1.10 2002/05/04 07:44:38 uebayasi Exp $

DISTNAME=		sylpheed-0.7.5
CATEGORIES=		mail news x11
MASTER_SITES=		http://sylpheed.good-day.net/sylpheed/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://sylpheed.good-day.net/index.cgi.en
COMMENT=	X based e-mail and netnews client

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-ipv6
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-gpgme

.include "../../security/gpgme/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
