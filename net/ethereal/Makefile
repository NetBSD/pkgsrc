# $NetBSD: Makefile,v 1.88 2003/12/13 00:45:25 wiz Exp $
#

DISTNAME=		ethereal-0.9.16
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.ethereal.com/pub/ethereal/ \
			ftp://ftp.sunet.se/pub/network/monitoring/ethereal/ \
			ftp://ftp.planetmirror.com/pub/ethereal/ \
			ftp://gd.tuwien.ac.at/infosys/security/ethereal/ \
			http://www.ethereal.com/distribution/ \
			http://ftp.sunet.se/pub/network/monitoring/ethereal/ \
			http://ethereal.netarc.jp/distribution/ \
			ftp://ftp.ethereal.com/pub/ethereal/old-versions/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		frueauf@NetBSD.org
HOMEPAGE=		http://www.ethereal.com/
COMMENT=		Network protocol analyzer

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_PERL5=		build

USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=        --enable-static=no
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-gtk-prefix=${BUILDLINK_PREFIX.gtk2}
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-net-snmp=${BUILDLINK_PREFIX.net-snmp}
CONFIGURE_ARGS+=	--with-pcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ENV+=		ac_cv_func_pcap_compile_nopcap=no

PTHREAD_OPTS=		require

.include "../../devel/zlib/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../net/net-snmp/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
