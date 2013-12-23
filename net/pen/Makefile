# $NetBSD: Makefile,v 1.17 2013/12/23 11:57:05 wiz Exp $

DISTNAME=	pen-0.17.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://siag.nu/pub/pen/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://siag.nu/pen/
COMMENT=	Load balancer for "simple" tcp based protocols

GNU_CONFIGURE=	YES

# Avoid pen complaining on NetBSD
CONFIGURE_ARGS+=	--with-fd_setsize=2048
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/pen
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
