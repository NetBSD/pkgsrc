# $NetBSD: Makefile,v 1.2 2004/02/14 17:21:33 jlam Exp $
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
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libcddb.pc.in
GNU_CONFIGURE=		yes

.include "../../misc/libcdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
