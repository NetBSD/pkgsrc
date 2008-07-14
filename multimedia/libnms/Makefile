# $NetBSD: Makefile,v 1.2 2008/07/14 12:56:09 joerg Exp $
#

DISTNAME=	libnms-0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.paldo.org/paldo/sources/libnms/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://streaming.polito.it/client/library/
COMMENT=	Open Media Streaming Client Library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libnms.pc.in

.include "../../mk/bsd.pkg.mk"
