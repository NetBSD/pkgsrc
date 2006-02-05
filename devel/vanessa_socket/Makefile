# $NetBSD: Makefile,v 1.5 2006/02/05 23:08:54 joerg Exp $
#

DISTNAME=		vanessa_socket-0.0.7
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://www.vergenet.net/linux/vanessa/download/vanessa_socket/0.0.7/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.vergenet.net/linux/vanessa/
COMMENT=		Library that simplifies TCP/IP socket operations

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/vanessa_logger/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
