# $NetBSD: Makefile,v 1.7 2003/05/02 11:55:14 wiz Exp $
#

DISTNAME=		eog-2.2.0
PKGREVISION=	2
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/eog/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Eye of GNOME: an image viewing and cataloging program

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES

GCONF2_SCHEMAS= 	eog.schemas

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
