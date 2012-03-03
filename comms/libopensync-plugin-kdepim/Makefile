# $NetBSD: Makefile,v 1.16 2012/03/03 00:12:51 wiz Exp $
#

DISTNAME=	libopensync-plugin-kdepim-0.22
PKGREVISION=	14
CATEGORIES=	comms
MASTER_SITES=	http://www.opensync.org/download/releases/0.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.opensync.org/
COMMENT=	Platform independent synchronization framework, kdepim plugin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

pre-build:
	cd ${WRKSRC}/src && ${MAKE} KNotesIface_stub.h

.include "../../comms/libopensync/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../misc/kdepim3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
