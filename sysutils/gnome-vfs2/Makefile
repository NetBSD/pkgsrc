# $NetBSD: Makefile,v 1.2 2002/09/11 23:07:50 rh Exp $
#

DISTNAME=		gnome-vfs-2.0.4
PKGNAME=		${DISTNAME:S/vfs/vfs2/}
PKGREVISION=		1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.1/sources/gnome-vfs/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Virtual File System (v2)

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_GNU_GETTEXT=	YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-platform-gnome-2

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../audio/cdparanoia/buildlink2.mk"
.include "../../databases/gnome-mime-data/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/ptl2/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../net/ORBit2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../sysutils/fam/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
