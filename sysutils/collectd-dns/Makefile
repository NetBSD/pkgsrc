# $NetBSD: Makefile,v 1.4 2019/08/11 13:23:04 wiz Exp $

COLLECTD_PACKAGE=	dns

COMMENT=		Statistics collection daemon - dns plugin
PKGREVISION=		2

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

# On NetBSD, built-in pcap lacks headers needed
.if ${OPSYS} == "NetBSD"
PREFER.libpcap=	pkgsrc
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
