# $NetBSD: Makefile,v 1.24 2000/08/24 01:25:36 kim Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp
#

DISTNAME=	zebra-0.88
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

BUILD_DEPENDS+=	automake:../../devel/automake

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.zebra.org/

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=/etc/zebra
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

#pre-configure:
#		cd ${WRKSRC} && automake

#post-build:
#		cd ${WRKSRC}/doc ; \
#		${TOUCH} zebra.texi ; \
#		makeinfo --no-split zebra.texi

post-install:
		@${CHMOD} a+r ${PREFIX}/share/examples/zebra/*

.include "../../mk/bsd.pkg.mk"
