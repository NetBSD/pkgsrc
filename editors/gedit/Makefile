# $NetBSD: Makefile,v 1.26 2004/02/14 17:21:39 jlam Exp $
#

DISTNAME=		gedit-2.4.1
PKGREVISION=		5
CATEGORIES=		editors gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gedit/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gedit.sourceforge.net/
COMMENT=		Lightweight GNOME2 text editor

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_PERL5=		build
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_X11=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

GCONF2_SCHEMAS=		gedit.schemas

CONFIGURE_ARGS+=	--enable-schemas-install

.include "../../textproc/scrollkeeper/omf.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
