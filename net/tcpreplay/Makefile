# $NetBSD: Makefile,v 1.9 2005/03/26 12:07:56 adrianp Exp $

DISTNAME=	tcpreplay-2.3.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tcpreplay.sourceforge.net/
COMMENT=	Replay saved tcpdump or snoop files

BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.6

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libnet=${BUILDLINK_PREFIX.libnet}
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}
CONFIGURE_ARGS+=	--without-pcapnav-config

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
