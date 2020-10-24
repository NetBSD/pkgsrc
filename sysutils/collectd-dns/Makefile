# $NetBSD: Makefile,v 1.7 2020/10/24 22:39:45 wiz Exp $

COLLECTD_PACKAGE=	dns

COMMENT=		Statistics collection daemon - dns plugin

.include "../../net/libpcap/buildlink3.mk"
COLLECTD_LIB.pcap=	${BUILDLINK_PREFIX.libpcap}

.include "../../sysutils/collectd/Makefile.common"

# On NetBSD, built-in pcap lacks headers needed
.if ${OPSYS} == "NetBSD"
PREFER.libpcap=	pkgsrc
.endif

.include "../../mk/bsd.pkg.mk"
