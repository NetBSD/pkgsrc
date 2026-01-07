# $NetBSD: Makefile,v 1.52 2026/01/07 08:46:04 wiz Exp $
#

DISTNAME=	libopensync-0.22
PKGREVISION=	42
CATEGORIES=	comms
##MASTER_SITES=	http://www.opensync.org/download/releases/0.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.opensync.org/
COMMENT=	Platform independent synchronization framework

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-python
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
