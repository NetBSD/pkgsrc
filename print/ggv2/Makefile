# $NetBSD: Makefile,v 1.24 2004/02/14 17:21:50 jlam Exp $
#

DISTNAME=		ggv-2.4.1
PKGREVISION=		1
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ggv/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 frontend for GhostScript

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES

GCONF2_SCHEMAS= 	ggv.schemas

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
