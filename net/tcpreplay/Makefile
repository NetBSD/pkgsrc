# $NetBSD: Makefile,v 1.20 2012/10/23 17:19:12 asau Exp $

DISTNAME=	tcpreplay-3.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcpreplay.synfin.net/
COMMENT=	Replay saved tcpdump or snoop files

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-dynamic-link
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
