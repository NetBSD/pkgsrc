# $NetBSD: Makefile,v 1.3 2012/10/31 11:17:11 asau Exp $
#

DISTNAME=	libbinio-1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libbinio/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://libbinio.sourceforge.net/
COMMENT=	Binary I/O stream class library

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libbinio.pc.in

.include "../../mk/bsd.pkg.mk"
