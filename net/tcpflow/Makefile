# $NetBSD: Makefile,v 1.8 2008/06/20 01:09:31 joerg Exp $
#

DISTNAME=	tcpflow-0.21
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	http://www.circlemud.org/pub/jelson/tcpflow/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.circlemud.org/~jelson/software/tcpflow/
COMMENT=	Captures data transmitted as part of TCP connections

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
