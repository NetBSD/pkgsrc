# $NetBSD: Makefile,v 1.23 2000/08/18 02:42:05 itojun Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp
#

DISTNAME=	zebra-0.88
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.zebra.org/

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=${PREFIX}/etc/zebra
USE_GTEXINFO=	yes

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
PLIST_SRC=	${WRKSRC}/PLIST
.else
CONFIGURE_ARGS+=--disable-ospf6d --disable-ripngd
PLIST_SRC=	${PKGDIR}/PLIST
.endif

.if defined(USE_INET6) && ${USE_INET6} == YES
post-patch:
		${CAT} ${PKGDIR}/PLIST.v6 ${PKGDIR}/PLIST > ${PLIST_SRC}
.endif

#post-build:
#		cd ${WRKSRC}/doc ; \
#		${TOUCH} zebra.texi ; \
#		makeinfo --no-split zebra.texi

.include "../../mk/bsd.pkg.mk"
