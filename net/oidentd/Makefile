# $NetBSD: Makefile,v 1.1.1.1 2004/01/03 23:21:44 tron Exp $

DISTNAME=	oidentd-2.0.7
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

post-configure:
	${ECHO} >>${WRKSRC}/config.h "#define PKG_SYSCONFDIR \"${PKG_SYSCONFDIR}\""

.include "../../mk/bsd.pkg.mk"
