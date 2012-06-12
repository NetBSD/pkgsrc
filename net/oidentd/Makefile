# $NetBSD: Makefile,v 1.13 2012/06/12 15:46:00 wiz Exp $

DISTNAME=	oidentd-2.0.7
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ojnk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dev.ojnk.net/
COMMENT=	Configurable IDENT server that supports NAT/IP masq

NOT_FOR_PLATFORM+=	NetBSD-[5-9]*-* NetBSD-1[0-9]*-*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
RCD_SCRIPTS=		oidentd
OSVERSION_SPECIFIC=	YES

PKG_OPTIONS_VAR=	PKG_OPTIONS.oidentd
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-patch:
	${ECHO} >>${WRKSRC}/config.h.in "#define PKG_SYSCONFDIR \"${PKG_SYSCONFDIR}\""

.include "../../mk/bsd.pkg.mk"
