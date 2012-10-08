# $NetBSD: Makefile,v 1.3 2012/10/08 09:21:07 asau Exp $
#

DISTNAME=	libnms-0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.paldo.org/paldo/sources/libnms/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://streaming.polito.it/client/library/
COMMENT=	Open Media Streaming Client Library

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libnms.pc.in

.include "../../mk/bsd.pkg.mk"
