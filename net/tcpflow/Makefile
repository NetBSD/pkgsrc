# $NetBSD: Makefile,v 1.4 2004/12/29 11:51:39 adrianp Exp $
#

DISTNAME=	tcpflow-0.21
CATEGORIES=	net security
MASTER_SITES=	http://www.circlemud.org/pub/jelson/tcpflow/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://www.circlemud.org/~jelson/software/tcpflow/
COMMENT=	Captures data transmitted as part of TCP connections

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
