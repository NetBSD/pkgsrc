# $NetBSD: Makefile,v 1.10 2001/10/18 15:20:30 veego Exp $

DISTNAME=		libpcap-0.6.1
SVR4_PKGNAME=		lpcap
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		System-independent interface for user-level packet capture

ONLY_FOR_PLATFORM=	SunOS-*-* Linux-*-*	# in NetBSD base system

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		flex-[0-9]*:../../devel/flex
.endif

.include "../../mk/bsd.pkg.mk"
