# $NetBSD: Makefile,v 1.1.1.1 2002/12/07 20:20:25 cjep Exp $

DISTNAME=	tcpreplay-1.2a
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://tcpreplay.sourceforge.net/
COMMENT=	Replay saved tcpdump or snoop files

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
