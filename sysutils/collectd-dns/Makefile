# $NetBSD: Makefile,v 1.6 2020/08/31 18:11:25 wiz Exp $

COLLECTD_PACKAGE=	dns

COMMENT=		Statistics collection daemon - dns plugin
PKGREVISION=		4

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

# On NetBSD, built-in pcap lacks headers needed
.if ${OPSYS} == "NetBSD"
PREFER.libpcap=	pkgsrc
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
