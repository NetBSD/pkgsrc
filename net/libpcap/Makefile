# $NetBSD: Makefile,v 1.5 2001/01/13 23:04:37 tron Exp $

DISTNAME=		libpcap-0.6.1
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.tcpdump.org/

BUILD_DEPENDS+=		bison:../../devel/bison
BUILD_DEPENDS+=		flex:../../devel/flex

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
