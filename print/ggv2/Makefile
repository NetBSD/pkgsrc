# $NetBSD: Makefile,v 1.20 2004/01/24 14:58:00 grant Exp $
#

DISTNAME=		ggv-2.4.0.2
PKGREVISION=		3
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ggv/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 frontend for GhostScript

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCONF2_SCHEMAS= 	ggv.schemas

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
