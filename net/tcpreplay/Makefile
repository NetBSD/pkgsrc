# $NetBSD: Makefile,v 1.5 2003/07/17 22:51:55 grant Exp $

DISTNAME=	tcpreplay-1.3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tcpreplay.sourceforge.net/
COMMENT=	Replay saved tcpdump or snoop files

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnetver=1.0.x

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
