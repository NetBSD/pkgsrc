# $NetBSD: Makefile,v 1.3 2004/08/20 07:10:53 cjs Exp $
#

DISTNAME=	tcpflow-0.20
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.circlemud.org/pub/jelson/tcpflow/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.circlemud.org/~jelson/software/tcpflow/
COMMENT=	Captures data transmitted as part of TCP connections

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
