# $NetBSD: Makefile,v 1.22 2003/11/12 03:39:41 jschauma Exp $

DISTNAME=		ntop-2.2
PKGNAME=		ntop2-2.2
PKGREVISION=		2
WRKSRC=                 ${WRKDIR}/${DISTNAME}/ntop
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ntop/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		adam@NetBSD.org
HOMEPAGE=		http://www.ntop.org/
COMMENT=		Shows network usage (similar to "top" for processes)

CONFLICTS=		ntop-[0-9]*

USE_X11=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=          yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# --enable-micro-ntop causes compile to fail 
CONFIGURE_ARGS+=	--enable-automake171
CONFIGURE_ARGS+=	--enable-sslv3
CONFIGURE_ARGS+=	--with-pcap-root=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-ossl-root=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-gdbm-root=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-zlib-root=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-gdchart-root=${BUILDLINK_PREFIX.gdchart}
CONFIGURE_ARGS+=	--with-gd-root=${BUILDLINK_PREFIX.gd}
CONFIGURE_ARGS+=	--with-libpng-root=${BUILDLINK_PREFIX.png}

PTHREAD_OPTS+=		require

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --automake
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${AUTOMAKE} -a --foreign -i
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../databases/gdbm/buildlink2.mk"
.include "../../graphics/gdchart/buildlink2.mk"
.include "../../net/libpcap/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
