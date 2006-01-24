# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:05 wiz Exp $

DISTNAME=	gtranslator-1.0.2
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtranslator/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtranslator.sourceforge.net/
COMMENT=	Gettext po file editor for the GNOME2 desktop environment

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MANCOMPRESSED=		yes

CONFIGURE_ARGS+=	--disable-debug

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
