# $NetBSD: Makefile,v 1.1.1.1 2002/09/11 23:31:16 rh Exp $
#

DISTNAME=	libgnome-2.0.4
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=2.0.1/sources/libgnome/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Core GNOME2 library (non-graphical)

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.libxml2=libxml2>=2.4.22
BUILDLINK_DEPENDS.esound=esound>=0.2.26

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_GNU_GETTEXT=	YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
