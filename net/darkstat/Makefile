# $NetBSD: Makefile,v 1.1.1.1 2006/07/19 04:41:47 minskim Exp $
#

DISTNAME=		darkstat-3.0.524
CATEGORIES=		net
MASTER_SITES=		http://dmr.ath.cx/net/darkstat/
DIST_SUBDIR=		darkstat
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://dmr.ath.cx/net/darkstat/
COMMENT=		Network statistics gatherer

BUILD_TARGET=		darkstat

GNU_CONFIGURE=		yes

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
