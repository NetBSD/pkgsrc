# $NetBSD: Makefile,v 1.2 2001/02/17 18:19:44 wiz Exp $

DISTNAME=		tcpdump-3.6.1
CATEGORIES=		net
MASTER_SITES= 		http://www.tcpdump.org/release/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.tcpdump.org/
COMMENT=		network monitoring tool

DEPENDS+=		libpcap>=0.6.1:../libpcap

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

GNU_CONFIGURE=		YES
USE_SSL=		YES

.include "../../mk/bsd.pkg.mk"
