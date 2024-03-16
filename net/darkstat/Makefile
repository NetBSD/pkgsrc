# $NetBSD: Makefile,v 1.19 2024/03/16 22:36:01 nia Exp $

DISTNAME=		darkstat-3.0.719
CATEGORIES=		net
MASTER_SITES=		https://unix4lyfe.org/darkstat/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://unix4lyfe.org/darkstat/
COMMENT=		Network statistics gatherer
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		darkstat

GNU_CONFIGURE=		yes

RCD_SCRIPTS=		darkstat

.include "../../mk/bsd.prefs.mk"

# Macs lacked clock_gettime way past its implement-by date.
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 101200
LDFLAGS+=	-lMacportsLegacySupport
.  include "../../devel/macports-legacy-support/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.6.0
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
