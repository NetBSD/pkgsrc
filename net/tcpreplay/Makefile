# $NetBSD: Makefile,v 1.6 2004/04/25 04:20:11 snj Exp $

DISTNAME=	tcpreplay-1.3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tcpreplay.sourceforge.net/
COMMENT=	Replay saved tcpdump or snoop files

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnetver=1.0.x

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
