# $NetBSD: Makefile,v 1.6 2012/03/03 00:12:51 wiz Exp $
#

DISTNAME=	msynctool-0.22
PKGREVISION=	4
CATEGORIES=	comms
MASTER_SITES=	http://www.opensync.org/download/releases/0.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.opensync.org/
COMMENT=	Command line tool for opensync framework

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../comms/libopensync/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
