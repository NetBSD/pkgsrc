# $NetBSD: Makefile,v 1.1.1.1 2003/04/10 17:08:13 wiz Exp $
#

DISTNAME=	tcpflow-0.20
CATEGORIES=	net security
MASTER_SITES=	http://www.circlemud.org/pub/jelson/tcpflow/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.circlemud.org/~jelson/software/tcpflow/
COMMENT=	Captures data transmitted as part of TCP connections

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../net/libpcap/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
