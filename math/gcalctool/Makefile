# $NetBSD: Makefile,v 1.70 2008/04/25 08:06:28 wiz Exp $
#

DISTNAME=		gcalctool-5.23.1
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcalctool/5.23/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://calctool.sourceforge.net/
COMMENT=		Desktop calculator for GNOME

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		HAVE_YACC=yes

USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_TOOLS+=		bison gmake intltool flex msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

GCONF_SCHEMAS=		gcalctool.schemas

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0

.include "../../devel/GConf/schemas.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
