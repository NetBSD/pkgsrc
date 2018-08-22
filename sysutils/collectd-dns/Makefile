# $NetBSD: Makefile,v 1.3 2018/08/22 09:46:32 wiz Exp $

COLLECTD_PACKAGE=	dns

COMMENT=		Statistics collection daemon - dns plugin
PKGREVISION=		1

.include "../../sysutils/collectd/Makefile.common"

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

# On NetBSD, built-in pcap lacks headers needed
.if ${OPSYS} == "NetBSD"
PREFER.libpcap=	pkgsrc
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
