# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:30 jlam Exp $
#

DISTNAME=		vanessa_socket-0.0.7
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://www.vergenet.net/linux/vanessa/download/vanessa_socket/0.0.7/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.vergenet.net/linux/vanessa/
COMMENT=		Library that simplifies TCP/IP socket operations

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/vanessa_logger/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
