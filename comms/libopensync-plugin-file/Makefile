# $NetBSD: Makefile,v 1.44 2025/10/23 20:36:06 wiz Exp $
#

DISTNAME=	libopensync-plugin-file-0.22
PKGREVISION=	39
CATEGORIES=	comms
##MASTER_SITES=	http://www.opensync.org/download/releases/0.22/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.opensync.org/
COMMENT=	Platform independent synchronization framework, backup to file

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../comms/libopensync/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
