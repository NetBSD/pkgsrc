# $NetBSD: Makefile,v 1.9 2005/12/05 23:55:14 rillig Exp $
#

DISTNAME=	pen-0.15.0
CATEGORIES=	net
MASTER_SITES=	http://siag.nu/pub/pen/					\
		ftp://siag.nu/pub/pen/

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
