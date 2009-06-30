# $NetBSD: Makefile,v 1.28 2009/06/30 00:07:21 joerg Exp $

DISTNAME=	ngrep-1.45
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ngrep/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ngrep.sourceforge.net/
COMMENT=	Network grep

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pcre
# ngrep's configure use --includedir/$includedir in a weird way!
CONFIGURE_ARGS+=	--includedir=${BUILDLINK_PREFIX.libpcap}/include
CONFIGURE_ARGS+=	--enable-ipv6
BUILD_TARGET=		ngrep

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
CONFIGURE_ARGS+=	--disable-pcap-restart
.endif

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux"
do-configure:
	cd ${WRKSRC} && ./configure --prefix=${PREFIX}
.endif

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
