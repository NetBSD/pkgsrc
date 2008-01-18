# $NetBSD: Makefile,v 1.48 2008/01/18 05:08:46 tnn Exp $

DISTNAME=	ntop-3.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ntop/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ntop.org/ntop.html
COMMENT=	Shows network usage (similar to "top" for processes)

CONFLICTS=	ntop-[0-9]*

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf autoheader automake gawk gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/ntop
CONFIGURE_ARGS+=	--with-gd-root=${BUILDLINK_PREFIX.gd}
CONFIGURE_ARGS+=	--with-gdbm-root=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-gdchart-root=${BUILDLINK_PREFIX.gdchart}
CONFIGURE_ARGS+=	--with-localedir=${PREFIX}/${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--with-libpng-root=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-ossl-root=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-pcap-root=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-zlib-root=${BUILDLINK_PREFIX.zlib}
# ntop-3.x crashes with IPv6
CONFIGURE_ARGS+=	--disable-ipv6
CONFIGURE_ARGS+=	--disable-snmp

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8.3

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-mt
.endif

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../databases/gdbm/buildlink3.mk"
.include "../../databases/rrdtool/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/gdchart/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
