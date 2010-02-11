# $NetBSD: Makefile,v 1.58 2010/02/11 22:24:33 joerg Exp $

DISTNAME=	ntop-3.3.10
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ntop/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.ntop.org/ntop.html
COMMENT=	Shows network usage (similar to "top" for processes)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	ntop-[0-9]*

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf autoheader automake gawk gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/ntop
CONFIGURE_ARGS+=	--with-gdbm-root=${BUILDLINK_PREFIX.gdbm}
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

.if ${OPSYS} == "Darwin"
# This package uses "-flat_namespace -undefined suppress" and exports
# symbols from the executable that get stripped unless we set this:
INSTALL_UNSTRIPPED=	YES
.endif

.if (${OPSYS} == "NetBSD" && !empty(OS_VERSION:M[0-4].*))
USE_BUILTIN.libevent=	no
.endif

pre-configure:
	set -e; cd ${WRKSRC}; \
	cp ${PREFIX}/share/libtool/config/ltmain.sh .; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../databases/gdbm/buildlink3.mk"
.include "../../databases/rrdtool/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../net/GeoIP/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
