# $NetBSD: Makefile,v 1.29 2004/10/03 00:17:56 tv Exp $

DISTNAME=		ntop-2.2
PKGNAME=		ntop2-2.2
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ntop/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		adam@NetBSD.org
HOMEPAGE=		http://www.ntop.org/
COMMENT=		Shows network usage (similar to "top" for processes)

CONFLICTS=		ntop-[0-9]*

WRKSRC=                 ${WRKDIR}/${DISTNAME}/ntop
USE_X11=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          yes
USE_LIBTOOL=		yes

# --enable-micro-ntop causes compile to fail 
CONFIGURE_ARGS+=	--enable-sslv3
CONFIGURE_ARGS+=	--with-pcap-root=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-ossl-root=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-gdbm-root=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-zlib-root=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-gdchart-root=${BUILDLINK_PREFIX.gdchart}
CONFIGURE_ARGS+=	--with-gd-root=${BUILDLINK_PREFIX.gd}
CONFIGURE_ARGS+=	--with-libpng-root=${BUILDLINK_PREFIX.png}

PTHREAD_OPTS+=		require

.include "../../databases/gdbm/buildlink3.mk"
.include "../../graphics/gdchart/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
