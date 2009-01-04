# $NetBSD: Makefile,v 1.3 2009/01/04 23:10:06 dbj Exp $
#

DISTNAME=		libvolume_id-0.81.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.marcuscom.com/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Library to provide file system type information

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	include lib lib/pkgconfig 
USE_TOOLS+=		gmake pkg-config

USE_LIBTOOL=yes

.include "../../mk/bsd.pkg.mk"
