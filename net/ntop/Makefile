# $NetBSD: Makefile,v 1.32 2005/01/11 19:38:20 xtraeme Exp $

DISTNAME=	ntop-3.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ntop/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ntop.org/
COMMENT=	Shows network usage (similar to "top" for processes)

CONFLICTS=	ntop-[0-9]*

WRKSRC=		${WRKDIR}/ntop

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/ntop
CONFIGURE_ARGS+=	--with-gd-root=${BUILDLINK_PREFIX.gd}
CONFIGURE_ARGS+=	--with-gdbm-root=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-gdchart-root=${BUILDLINK_PREFIX.gdchart}
CONFIGURE_ARGS+=	--with-localedir=${LOCALBASE}/${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--with-libpng-root=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-ossl-root=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-pcap-root=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-zlib-root=${BUILDLINK_PREFIX.zlib}
# ntop-3.x crashes with IPv6
CONFIGURE_ARGS+=	--disable-ipv6

PTHREAD_OPTS+=		require

BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.8.3

.include "../../databases/gdbm/buildlink3.mk"
.include "../../graphics/gdchart/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
