# $NetBSD: Makefile,v 1.25 2005/05/22 20:08:25 jlam Exp $

DISTNAME=		libpcap-0.8.3
SVR4_PKGNAME=		lpcap
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		System-independent interface for user-level packet capture

NOT_FOR_PLATFORM+=	Interix-*-* # no raw interface access

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# tarball contains invalid dir entry libpcap-0.8.3/.; breaks "first" extract
EXTRACT_ELEMENTS=	libpcap-0.8.3/./*

GNU_CONFIGURE=		yes
USE_TOOLS+=		bison gm4 lex

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
.  if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
