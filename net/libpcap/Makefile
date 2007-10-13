# $NetBSD: Makefile,v 1.40 2007/10/13 22:14:15 tron Exp $

DISTNAME=	libpcap-0.9.8
SVR4_PKGNAME=	lpcap
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcpdump.org/
COMMENT=	System-independent interface for user-level packet capture

NOT_FOR_PLATFORM+=	Interix-*-* # no raw interface access

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		bison gm4 lex
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if exists(/usr/include/net/pfvar.h) && !exists(/usr/include/net/if_pflog.h)
SUBST_CLASSES+=		pflog
SUBST_MESSAGE.pflog=	Disabling pflog(4) support because "net/if_pflog.h" is missing.
SUBST_STAGE.pflog=	post-configure
SUBST_FILES.pflog=	config.h
SUBST_SED.pflog=	-e 's/^\#define.*HAVE_NET_PFVAR_H.*//'
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/pcap-int.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
