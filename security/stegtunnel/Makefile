# $NetBSD: Makefile,v 1.1.1.1 2008/05/09 21:39:17 agc Exp $

DISTNAME=	stegtunnel-0.4
CATEGORIES=	security
MASTER_SITES=	http://www.synacklabs.net/projects/stegtunnel/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.synacklabs.net/projects/stegtunnel/
COMMENT=	Provides a covert channel in the IPID and sequence number

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
