# $NetBSD: Makefile,v 1.3 2003/06/02 01:17:41 jschauma Exp $

DISTNAME=	tcpreplay-1.3.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcpreplay/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://tcpreplay.sourceforge.net/
COMMENT=	Replay saved tcpdump or snoop files

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
