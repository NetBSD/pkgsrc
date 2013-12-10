# $NetBSD: Makefile,v 1.8 2013/12/10 12:36:35 jperkin Exp $

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
