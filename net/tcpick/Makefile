# $NetBSD: Makefile,v 1.7 2013/02/06 19:31:01 jperkin Exp $

DISTNAME=	tcpick-0.2.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpick/}

MAINTAINER=	josediazfer@yahoo.es
HOMEPAGE=	http://tcpick.sourceforge.net/
COMMENT=	Simple tcp sniffer with tcpdump-style rules

GNU_CONFIGURE=	YES

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
