# $NetBSD: Makefile,v 1.6 2004/04/22 16:08:47 recht Exp $
#

DISTNAME=	libcddb-0.9.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcddb/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://libcddb.sourceforge.net/
COMMENT=	Library to access data on a CDDB server

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libcddb.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
