# $NetBSD: Makefile,v 1.10 2020/03/20 11:58:11 nia Exp $

DISTNAME=	tcpick-0.2.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpick/}

MAINTAINER=	josediazfer@yahoo.es
HOMEPAGE=	http://tcpick.sourceforge.net/
COMMENT=	Simple tcp sniffer with tcpdump-style rules

GNU_CONFIGURE=	YES

CFLAGS.SunOS+=	-Du_int16_t=uint16_t -Du_int32_t=uint32_t

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
