# $NetBSD: Makefile,v 1.12 2003/12/28 23:37:06 jmmv Exp $
#

DISTNAME=		gcalctool-4.2.83
PKGREVISION=		5
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=calctool/}

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://calctool.sourceforge.net/
COMMENT=		Gtk2+ version of calctool

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		gcalctool.schemas

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
