# $NetBSD: Makefile,v 1.6 2001/02/17 18:19:04 wiz Exp $

DISTNAME=		libpcap-0.6.1
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		System-independent interface for user-level packet capture

BUILD_DEPENDS+=		bison:../../devel/bison
BUILD_DEPENDS+=		flex:../../devel/flex

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
