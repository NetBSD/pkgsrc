# $NetBSD: Makefile,v 1.41 2001/06/12 20:33:07 jlam Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp
#

DISTNAME=	zebra-0.91a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.zebra.org/
COMMENT=	Free multithreaded routing daemon software

BUILD_DEPENDS+=	automake-1.4:../../devel/automake
BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=		# empty

.if defined(USE_ZEBRA_VTYSH) && ${USE_ZEBRA_VTYSH} == "YES"
USE_GNU_READLINE=	uses rl_pending_input
.include "../../devel/readline/buildlink.mk"
CONFIGURE_ARGS+=	--enable-vtysh
PLIST_SRC+=		${PKGDIR}/PLIST.vtysh
.else
CONFIGURE_ARGS+=	--disable-vtysh
.endif

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--sysconfdir=/etc/zebra
USE_GTEXINFO=		# defined
USE_GMAKE=		# defined

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == YES
PLIST_SRC+=		${PKGDIR}/PLIST.v6
.else
CONFIGURE_ARGS+=	--disable-ospf6d
CONFIGURE_ARGS+=	--disable-ripngd
.endif

PLIST_SRC+=		${PKGDIR}/PLIST

LIBS+=			${LDFLAGS}

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf
#	cd ${WRKSRC} && ${LOCALBASE}/bin/automake

#post-build:
#	cd ${WRKSRC}/doc ; \
#	${TOUCH} zebra.texi ; \
#	makeinfo --no-split zebra.texi

post-install:
	@${CHMOD} a+r ${PREFIX}/share/examples/zebra/*

.include "../../mk/bsd.pkg.mk"
