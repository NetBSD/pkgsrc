# $NetBSD: Makefile,v 1.21 2004/10/05 19:00:57 adrianp Exp $

DISTNAME=		libpcap-0.8.3
SVR4_PKGNAME=		lpcap
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		System-independent interface for user-level packet capture

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		lex yacc m4

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
.  if exists(/usr/include/netinet/ip6.h)
CONFIGURE_ARGS+=	--enable-ipv6
.  endif
.endif

.include "../../mk/bsd.pkg.mk"
