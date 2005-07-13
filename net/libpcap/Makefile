# $NetBSD: Makefile,v 1.26 2005/07/13 14:31:49 drochner Exp $

DISTNAME=		libpcap-0.9.1
SVR4_PKGNAME=		lpcap
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		System-independent interface for user-level packet capture

NOT_FOR_PLATFORM+=	Interix-*-* # no raw interface access

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_TOOLS+=		bison gm4 lex

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
.  if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
