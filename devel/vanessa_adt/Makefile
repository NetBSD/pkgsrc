# $NetBSD: Makefile,v 1.6 2010/06/02 12:42:38 adam Exp $

DISTNAME=	vanessa_adt-0.0.8
CATEGORIES=	devel
MASTER_SITES=	http://www.vergenet.net/linux/vanessa/download/vanessa_adt/0.0.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vergenet.net/linux/vanessa/
COMMENT=	Library that provides Abstract Data Types (ADTs)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/vanessa_logger/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
