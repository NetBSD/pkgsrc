# $NetBSD: Makefile,v 1.1.1.1 2001/01/13 23:29:28 tron Exp $

DISTNAME=		tcpdump-3.6.1
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.tcpdump.org/

DEPENDS+=		libpcap>=0.6.1:../libpcap

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

GNU_CONFIGURE=		YES
USE_SSL=		YES

.include "../../mk/bsd.pkg.mk"
