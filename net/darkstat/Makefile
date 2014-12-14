# $NetBSD: Makefile,v 1.16 2014/12/14 08:39:56 obache Exp $

DISTNAME=		darkstat-3.0.718
CATEGORIES=		net
MASTER_SITES=		http://unix4lyfe.org/darkstat/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://unix4lyfe.org/darkstat/
COMMENT=		Network statistics gatherer
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		darkstat

GNU_CONFIGURE=		yes

RCD_SCRIPTS=		darkstat

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.6.0
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
