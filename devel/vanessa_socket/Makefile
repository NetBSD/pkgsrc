# $NetBSD: Makefile,v 1.1.1.1 2004/09/25 00:05:06 grant Exp $
#

DISTNAME=		vanessa_socket-0.0.7
CATEGORIES=		devel
MASTER_SITES=		http://www.vergenet.net/linux/vanessa/download/vanessa_socket/0.0.7/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.vergenet.net/linux/vanessa/
COMMENT=		Library that simplifies TCP/IP socket operations

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/vanessa_logger/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
