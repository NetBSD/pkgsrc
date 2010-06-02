# $NetBSD: Makefile,v 1.8 2010/06/02 12:43:37 adam Exp $

DISTNAME=	vanessa_socket-0.0.10
CATEGORIES=	devel
MASTER_SITES=	http://www.vergenet.net/linux/vanessa/download/vanessa_socket/0.0.10/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vergenet.net/linux/vanessa/
COMMENT=	Library that simplifies TCP/IP socket operations

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/vanessa_logger/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
