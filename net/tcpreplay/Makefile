# $NetBSD: Makefile,v 1.2 2003/02/15 23:54:45 salo Exp $

DISTNAME=	tcpreplay-1.3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://tcpreplay.sourceforge.net/
COMMENT=	Replay saved tcpdump or snoop files

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
