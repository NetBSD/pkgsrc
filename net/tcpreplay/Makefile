# $NetBSD: Makefile,v 1.26 2020/06/21 15:30:39 nia Exp $

DISTNAME=	tcpreplay-4.3.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=appneta/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tcpreplay.appneta.com/
COMMENT=	Replay saved tcpdump or snoop files
LICENSE=	gnu-gpl-v3

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-dynamic-link
CONFIGURE_ARGS+=	--with-libpcap=${BUILDLINK_PREFIX.libpcap}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
