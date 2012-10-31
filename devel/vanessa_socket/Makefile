# $NetBSD: Makefile,v 1.10 2012/10/31 11:19:53 asau Exp $

DISTNAME=	vanessa_socket-0.0.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.vergenet.net/linux/vanessa/download/vanessa_socket/0.0.10/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vergenet.net/linux/vanessa/
COMMENT=	Library that simplifies TCP/IP socket operations

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/vanessa_logger/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
