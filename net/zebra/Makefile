# $NetBSD: Makefile,v 1.59 2003/11/18 16:34:13 wiz Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp
#

DISTNAME=	zebra-0.93b
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.zebra.org/
COMMENT=	Free multithreaded routing daemon software

.include "../../mk/bsd.prefs.mk"

AUTOMAKE_REQD=		1.4
USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
PKG_SYSCONFSUBDIR?=	zebra
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
# you might need debugging, it's a developer release !
#CFLAGS+=	-g

CONFLICTS+=		quagga-[0-9]*

PLIST_SRC=		# empty

INFO_FILES=	zebra.info

.if defined(USE_ZEBRA_VTYSH) && ${USE_ZEBRA_VTYSH} == "YES"
USE_GNU_READLINE=	# uses rl_pending_input
.  include "../../devel/readline/buildlink2.mk"
CONFIGURE_ARGS+=	--enable-vtysh
PLIST_SRC+=		${PKGDIR}/PLIST.vtysh
.else
CONFIGURE_ARGS+=	--disable-vtysh
.endif

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
	cd ${WRKSRC} && ${AUTORECONF} --force
#	cd ${WRKSRC} && ${AUTOMAKE}

#post-build:
#	cd ${WRKSRC}/doc ; \
#	${TOUCH} zebra.texi ; \
#	${MAKEINFO} --no-split zebra.texi

post-install:
	@${CHMOD} a+r ${PREFIX}/share/examples/zebra/*

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
