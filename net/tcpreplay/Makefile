# $NetBSD: Makefile,v 1.17 2007/08/20 21:06:15 adrianp Exp $

DISTNAME=	tcpreplay-3.1.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcpreplay.synfin.net/
COMMENT=	Replay saved tcpdump or snoop files

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.7.2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
