# $NetBSD: Makefile,v 1.107 2005/04/28 16:46:44 tron Exp $

DISTNAME=		ethereal-0.10.10
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.ethereal.com/distribution/ \
			http://ethereal.planetmirror.com/distribution/ \
			http://www.mirrors.wiretapped.net/security/packet-capture/ethereal/ \
			http://netmirror.org/mirror/ftp.ethereal.com/ \
			http://ethereal.secuwiz.com/distribution/ \
			http://ethereal.0ni0n.org/distribution/ \
			ftp://ftp.ethereal.com/pub/ethereal/ \
			ftp://ftp.sunet.se/pub/network/monitoring/ethereal/ \
			ftp://ftp.planetmirror.com/pub/ethereal/ \
			ftp://gd.tuwien.ac.at/infosys/security/ethereal/ \
			http://ftp.sunet.se/pub/network/monitoring/ethereal/ \
			http://ethereal.netarc.jp/distribution/ \
			ftp://ftp.ethereal.com/pub/ethereal/old-versions/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		frueauf@NetBSD.org
HOMEPAGE=		http://www.ethereal.com/
COMMENT=		Network protocol analyzer

USE_X11=		YES
USE_PERL5=		build

USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-gtk2
CONFIGURE_ARGS+=        --enable-static=no
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--with-gtk-prefix=${BUILDLINK_PREFIX.gtk2}
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
CONFIGURE_ARGS+=	--with-net-snmp
CONFIGURE_ARGS+=	--with-pcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ENV+=		ac_cv_func_pcap_compile_nopcap=no

PTHREAD_OPTS=		require

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
USE_BUILTIN.libpcap=	no
.endif

# This work arround should be removed when the packages gets updated
# to a newer version.
post-patch:
	${TOUCH} ${WRKSRC}/epan/dissectors/register.c

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
