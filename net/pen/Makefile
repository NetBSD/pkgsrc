# $NetBSD: Makefile,v 1.12 2008/01/30 08:27:30 ghen Exp $
#

DISTNAME=	pen-0.17.2
CATEGORIES=	net
MASTER_SITES=	http://siag.nu/pub/pen/					\
		ftp://siag.nu/pub/pen/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://siag.nu/pen/
COMMENT=	Load balancer for "simple" tcp based protocols

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

# Avoid pen complaining on NetBSD
CONFIGURE_ARGS+=	--with-fd_setsize=2048
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/pen
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
