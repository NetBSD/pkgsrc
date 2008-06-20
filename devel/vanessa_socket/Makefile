# $NetBSD: Makefile,v 1.7 2008/06/20 01:09:17 joerg Exp $
#

DISTNAME=		vanessa_socket-0.0.7
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		http://www.vergenet.net/linux/vanessa/download/vanessa_socket/0.0.7/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.vergenet.net/linux/vanessa/
COMMENT=		Library that simplifies TCP/IP socket operations

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/vanessa_logger/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
