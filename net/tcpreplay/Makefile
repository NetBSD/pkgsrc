# $NetBSD: Makefile,v 1.4 2003/06/10 02:00:36 jmc Exp $

DISTNAME=	tcpreplay-1.3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://tcpreplay.sourceforge.net/
COMMENT=	Replay saved tcpdump or snoop files

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnetver=1.0.x

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
