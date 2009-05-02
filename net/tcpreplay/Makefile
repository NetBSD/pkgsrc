# $NetBSD: Makefile,v 1.19 2009/05/02 17:35:43 minskim Exp $

DISTNAME=	tcpreplay-3.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcpreplay.synfin.net/
COMMENT=	Replay saved tcpdump or snoop files

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-dynamic-link
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
