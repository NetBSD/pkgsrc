# $NetBSD: Makefile,v 1.1.1.1 2004/02/23 17:53:33 minskim Exp $

DISTNAME= 	tcpick-0.1.19
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpick/}

MAINTAINER=	josediazfer@yahoo.es
HOMEPAGE=	http://tcpick.sourceforge.net/
COMMENT=	Simple tcp sniffer with tcpdump-style rules

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
