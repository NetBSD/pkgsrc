# $NetBSD: Makefile,v 1.11 1999/07/27 13:42:21 itojun Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp
#

DISTNAME=	zebra-0.74
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.zebra.org/

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6)
PLIST_SRC=	${PKGDIR}/PLIST.v6
.else
CONFIGURE_ARGS+=--disable-ospf6d --disable-ripngd
PLIST_SRC=	${PKGDIR}/PLIST
.endif

.include "../../mk/bsd.pkg.mk"
