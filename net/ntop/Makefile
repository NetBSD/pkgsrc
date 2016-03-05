# $NetBSD: Makefile,v 1.95 2016/03/05 11:29:09 jperkin Exp $

DISTNAME=	ntop-4.1.0
PKGREVISION=	24
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ntop/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ntop.org/products/ntop/
COMMENT=	Shows network usage (similar to "top" for processes)
LICENSE=	gnu-gpl-v3

CONFLICTS=	ntop-[0-9]*
DEPENDS+=	${PYPKGPREFIX}-mako-[0-9]*:../../devel/py-mako

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf autoheader automake gawk gmake gunzip
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/ntop
CONFIGURE_ARGS+=	--with-gdbm-root=${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--with-ossl-root=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-pcap-root=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--with-zlib-root=${BUILDLINK_PREFIX.zlib}

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8.3

.include "../../mk/pthread.buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-mt
.endif

.if (${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[0-4].*))
USE_BUILTIN.libevent=	no
.endif

pre-configure:
	set -e; cd ${WRKSRC}; \
	libtoolize -c -f; cp m4/libtool.m4 libtool.m4.in; \
	cat acinclude.m4.in libtool.m4.in acinclude.m4.ntop > acinclude.m4; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../databases/gdbm/buildlink3.mk"
.include "../../databases/rrdtool/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
