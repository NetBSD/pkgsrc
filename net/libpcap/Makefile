# $NetBSD: Makefile,v 1.15 2004/02/18 18:44:37 minskim Exp $

DISTNAME=		libpcap-0.7.2
SVR4_PKGNAME=		lpcap
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		System-independent interface for user-level packet capture

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		flex-[0-9]*:../../devel/flex
.  if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
