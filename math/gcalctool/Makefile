# $NetBSD: Makefile,v 1.55 2006/07/05 05:37:42 jlam Exp $
#

DISTNAME=		gcalctool-5.7.32
PKGREVISION=		1
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcalctool/5.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://calctool.sourceforge.net/
COMMENT=		Desktop calculator for GNOME

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		HAVE_YACC=yes

USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_TOOLS+=		bison gmake intltool msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		gcalctool.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
