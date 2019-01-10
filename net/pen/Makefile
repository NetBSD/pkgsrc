# $NetBSD: Makefile,v 1.21 2019/01/10 14:58:56 schmonz Exp $

DISTNAME=	pen-0.34.1
CATEGORIES=	net
MASTER_SITES=	http://siag.nu/pub/pen/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://siag.nu/pen/
COMMENT=	Load balancer for "simple" tcp based protocols
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

# Avoid pen complaining on NetBSD
CONFIGURE_ARGS+=	--with-fd_setsize=2048
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/pen
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
