# $NetBSD: Makefile,v 1.36.4.1 2007/08/13 08:17:50 ghen Exp $

DISTNAME=		libpcap-0.9.7
SVR4_PKGNAME=		lpcap
CATEGORIES=		net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		System-independent interface for user-level packet capture

NOT_FOR_PLATFORM+=	Interix-*-* # no raw interface access

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_TOOLS+=		bison gm4 lex
USE_LIBTOOL=		yes

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/pcap-int.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
