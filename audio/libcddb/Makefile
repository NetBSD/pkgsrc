# $NetBSD: Makefile,v 1.1.1.1 2004/01/17 15:25:37 recht Exp $
#

DISTNAME=	libcddb-0.9.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcddb/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://libcddb.sourceforge.net/
COMMENT=	Library to access data on a CDDB server

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libcddb.pc.in
GNU_CONFIGURE=		yes

.include "../../misc/libcdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
