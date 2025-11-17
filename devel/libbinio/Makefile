# $NetBSD: Makefile,v 1.7 2025/11/17 11:00:36 wiz Exp $

DISTNAME=	libbinio-1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libbinio/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	https://libbinio.sourceforge.net/
COMMENT=	Binary I/O stream class library

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libbinio.pc.in

.include "../../mk/bsd.pkg.mk"
