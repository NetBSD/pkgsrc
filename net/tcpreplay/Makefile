# $NetBSD: Makefile,v 1.18 2008/06/20 01:09:31 joerg Exp $

DISTNAME=	tcpreplay-3.1.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcpreplay.synfin.net/
COMMENT=	Replay saved tcpdump or snoop files

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.7.2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
