# $NetBSD: Makefile,v 1.14 2002/07/19 02:34:34 hubertf Exp $

DISTNAME=		sylpheed-0.8.0
CATEGORIES=		mail news x11
MASTER_SITES=		http://sylpheed.good-day.net/sylpheed/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://sylpheed.good-day.net/index.cgi.en
COMMENT=	X based e-mail and netnews client

CONFLICTS=	sylpheed-claws-*

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-gpgme
CONFIGURE_ARGS+=	--enable-compface

.include "../../mk/bsd.prefs.mk"
BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.include "../../graphics/compface/buildlink.mk"
.include "../../security/gpgme/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
