# $NetBSD: Makefile,v 1.27 2000/10/29 15:35:35 itojun Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp
#

DISTNAME=	zebra-0.89a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.zebra.org/

BUILD_DEPENDS+=	automake:../../devel/automake
BUILD_DEPENDS+=	autoreconf:../../devel/autoconf

.include "../../mk/bsd.prefs.mk"

# libedit does not work due to missing functions.
.if defined(USE_ZEBRA_VTYSH) && ${USE_ZEBRA_VTYSH} == "YES"
DEPENDS+=	readline-*:../../devel/readline
CONFIGURE_ARGS+=--enable-vtysh
CONFIGURE_ENV+=	LIBS=-L${LOCALBASE}/lib CPPFLAGS=-I${LOCALBASE}/include
.else
CONFIGURE_ARGS+=--disable-vtysh
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--sysconfdir=/etc/zebra
USE_GTEXINFO=	yes
USE_GMAKE=	yes

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == YES
.else
CONFIGURE_ARGS+=--disable-ospf6d --disable-ripngd
.endif
PLIST_SRC=	${WRKDIR}/PLIST

post-patch:
		${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
.if defined(USE_INET6) && ${USE_INET6} == YES
		${CAT} ${PKGDIR}/PLIST.v6 >> ${PLIST_SRC}
.endif
.if defined(USE_ZEBRA_VTYSH) && ${USE_ZEBRA_VTYSH} == "YES"
		${CAT} ${PKGDIR}/PLIST.vtysh >> ${PLIST_SRC}
.endif
		${ECHO} '@dirrm share/examples/zebra' >>${PLIST_SRC}

pre-configure:
		cd ${WRKSRC} && autoreconf
#		cd ${WRKSRC} && automake

#post-build:
#		cd ${WRKSRC}/doc ; \
#		${TOUCH} zebra.texi ; \
#		makeinfo --no-split zebra.texi

post-install:
		@${CHMOD} a+r ${PREFIX}/share/examples/zebra/*

.include "../../mk/bsd.pkg.mk"
