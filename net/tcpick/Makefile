# $NetBSD: Makefile,v 1.5 2008/06/20 01:09:31 joerg Exp $

DISTNAME=	tcpick-0.2.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpick/}

MAINTAINER=	josediazfer@yahoo.es
HOMEPAGE=	http://tcpick.sourceforge.net/
COMMENT=	Simple tcp sniffer with tcpdump-style rules

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
