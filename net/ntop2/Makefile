# $NetBSD: Makefile,v 1.14 2003/05/02 11:56:10 wiz Exp $

DISTNAME=		ntop-2.1.54
PKGNAME=		ntop2-2.1.54
PKGREVISION=	2
WRKSRC=                 ${WRKDIR}/${DISTNAME}/ntop
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ntop/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.ntop.org/
COMMENT=		shows network usage (similar to "top" for processes)

CONFLICTS=		ntop-[0-9]*

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=          yes
USE_GNU_READLINE=	yes
# --enable-micro-ntop causes compile to fail 
CONFIGURE_ARGS+=	--enable-automake171
CONFIGURE_ARGS+=	--with-pcap-root=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-gdbm-root=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-gdchart-root=${BUILDLINK_PREFIX.gdchart}
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PTHREAD_OPTS+=		require

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --automake
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../net/libpcap/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../graphics/gdchart/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
