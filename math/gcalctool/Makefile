# $NetBSD: Makefile,v 1.39 2005/06/21 18:18:57 jlam Exp $
#

DISTNAME=		gcalctool-5.5.42
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcalctool/5.5/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://calctool.sourceforge.net/
COMMENT=		Desktop calculator for GNOME

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		HAVE_YACC=yes

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		bison gmake
USE_PKGLOCALEDIR=	yes

GCONF2_SCHEMAS=		gcalctool.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/atk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
