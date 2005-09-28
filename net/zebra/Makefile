# $NetBSD: Makefile,v 1.69 2005/09/28 20:52:25 rillig Exp $
# Based on KAME Id: Makefile,v 1.1.2.1.2.1.10.2 1999/01/05 11:03:50 itojun Exp

DISTNAME=	zebra-0.95
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.zebra.org/pub/zebra/ \
		ftp://ftp.ripe.net/mirrors/sites/ftp.zebra.org/pub/zebra/ \
		ftp://ftp.sunet.se/pub/network/zebra/

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.zebra.org/
COMMENT=	Free multithreaded routing daemon software

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${INFO_DIR}

PKG_SYSCONFSUBDIR?=	zebra
EGDIR=		${PREFIX}/share/examples/zebra
CONF_FILES=	${EGDIR}/bgpd.conf.sample ${PKG_SYSCONFDIR}/bgpd.conf \
		${EGDIR}/ospfd.conf.sample ${PKG_SYSCONFDIR}/ospfd.conf \
		${EGDIR}/ripd.conf.sample ${PKG_SYSCONFDIR}/ripd.conf \
		${EGDIR}/zebra.conf.sample ${PKG_SYSCONFDIR}/zebra.conf
# with optimization, the timer/scheduler (esp. for MRT dump rotation) appears
# to have problems.
CFLAGS=	-O0

CONFLICTS+=		quagga-[0-9]*

PLIST_SRC=		# empty

INFO_FILES=		zebra.info

BUILD_DEFS+=		USE_ZEBRA_VTYSH

.include "../../mk/bsd.prefs.mk"

.if defined(USE_ZEBRA_VTYSH) && ${USE_ZEBRA_VTYSH} == "YES"
USE_GNU_READLINE=	# uses rl_pending_input
.  include "../../devel/readline/buildlink3.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.vtysh
CONFIGURE_ARGS+=	--enable-vtysh
CONF_FILES+=		${EGDIR}/vtysh.conf.sample ${PKG_SYSCONFDIR}/vtysh.conf
.else
CONFIGURE_ARGS+=	--disable-vtysh
.endif

USE_TOOLS+=		automake gmake
USE_MAKEINFO=		yes
.include "../../devel/readline/buildlink3.mk"

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && ${USE_INET6} == "YES"
PLIST_SRC+=		${PKGDIR}/PLIST.v6
CONFIGURE_ARGS+=	--enable-ipv6
CONF_FILES+=	${EGDIR}/ospf6d.conf.sample ${PKG_SYSCONFDIR}/ospf6d.conf \
		${EGDIR}/ripngd.conf.sample ${PKG_SYSCONFDIR}/ripngd.conf
.else
CONFIGURE_ARGS+=	--disable-ipv6
CONFIGURE_ARGS+=	--disable-ospf6d
CONFIGURE_ARGS+=	--disable-ripngd
.endif

PLIST_SRC+=		${PKGDIR}/PLIST

LIBS+=			${LDFLAGS}

pre-configure:
	cd ${WRKSRC} && autoreconf --force
#	cd ${WRKSRC} && automake

#post-build:
#	cd ${WRKSRC}/doc ; \
#	${TOUCH} zebra.texi ; \
#	${MAKEINFO} --no-split zebra.texi

post-install:
	@${CHMOD} a+r ${PREFIX}/share/examples/zebra/*

.include "../../mk/bsd.pkg.mk"
