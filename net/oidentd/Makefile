# $NetBSD: Makefile,v 1.5 2005/02/24 15:49:26 tron Exp $

DISTNAME=	oidentd-2.0.7
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ojnk/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://dev.ojnk.net/
COMMENT=	Configurable IDENT server that supports NAT/IP masq

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_PKGINSTALL=		YES
RCD_SCRIPTS=		oidentd

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_INET6
.if defined(USE_INET6) && ${USE_INET6} != "YES"
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-patch:
	${ECHO} >>${WRKSRC}/config.h.in "#define PKG_SYSCONFDIR \"${PKG_SYSCONFDIR}\""

.include "../../mk/bsd.pkg.mk"
