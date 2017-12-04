# $NetBSD: Makefile,v 1.23 2017/12/04 09:32:01 he Exp $

VERSION=	4.2.6
DISTNAME=	tcpreplay-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=appneta/tcpreplay/releases/download/v${VERSION}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcpreplay.appneta.com/wiki/installation.html
COMMENT=	Replay saved tcpdump or snoop files
LICENSE=	gnu-gpl-v3

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-dynamic-link
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
