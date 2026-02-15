# $NetBSD: Makefile,v 1.20 2026/02/15 13:58:07 wiz Exp $

DISTNAME=		darkstat-3.0.722
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=emikulic/}

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		https://unix4lyfe.org/darkstat/
COMMENT=		Network statistics gatherer
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		darkstat

USE_TOOLS+=		autoconf autoheader
GNU_CONFIGURE=		yes

RCD_SCRIPTS=		darkstat

.include "../../mk/bsd.prefs.mk"

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC} && autoheader

# Macs lacked clock_gettime way past its implement-by date.
.if ${OPSYS} == "Darwin" && ${OPSYS_VERSION} < 101200
LDFLAGS+=	-lMacportsLegacySupport
.  include "../../devel/macports-legacy-support/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=1.10.0
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
