# $NetBSD: Makefile,v 1.15 2012/09/15 10:03:58 obache Exp $
#

DISTNAME=	libopensync-plugin-evolution2-0.22
PKGREVISION=	11
CATEGORIES=	comms
MASTER_SITES=	http://www.opensync.org/download/releases/0.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opensync.org/
COMMENT=	Platform independent synchronization framework, evo plugin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-DHANDLE_LIBICAL_MEMORY

.include "../../comms/libopensync/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
