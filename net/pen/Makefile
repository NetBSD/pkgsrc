# $NetBSD: Makefile,v 1.7 2003/10/30 23:36:29 xtraeme Exp $
#

DISTNAME=	pen-0.12.0
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

.include "../../mk/bsd.pkg.mk"
