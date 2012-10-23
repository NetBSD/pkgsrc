# $NetBSD: Makefile,v 1.15 2012/10/23 17:18:57 asau Exp $
#

DISTNAME=	pen-0.17.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://siag.nu/pub/pen/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://siag.nu/pen/
COMMENT=	Load balancer for "simple" tcp based protocols

GNU_CONFIGURE=	YES

# Avoid pen complaining on NetBSD
CONFIGURE_ARGS+=	--with-fd_setsize=2048
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/pen
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
