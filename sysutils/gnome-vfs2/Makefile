# $NetBSD: Makefile,v 1.1.1.1 2002/09/07 03:04:06 rh Exp $
#

DISTNAME=		gnome-vfs-2.0.4
PKGNAME=		gnome-vfs2-2.0.4
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.1/sources/gnome-vfs/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System (v2)

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_GNU_GETTEXT=	YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltmain.sh

post-configure:
	chmod +x ${WRKSRC}/ltmain.sh
	( cd ${WRKSRC} && ./ltmain.sh )

.include "../../databases/gnome-mime-data/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/ptl2/buildlink2.mk"
.include "../../sysutils/fam/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
