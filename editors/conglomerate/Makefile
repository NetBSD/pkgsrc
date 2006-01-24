# $NetBSD: Makefile,v 1.36 2006/01/24 07:32:05 wiz Exp $
#

DISTNAME=	conglomerate-0.9.0
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=conglomerate/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.conglomerate.org/
COMMENT=	XML editor for GNOME2

BUILD_USES_MSGFMT=	yes
DEPENDS+=		docbook-xsl>=1.64.1:../../textproc/docbook-xsl
DEPENDS+=		docbook-xml>=4.2nb6:../../textproc/docbook-xml

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome2-1.5
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--enable-printing
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

GCONF2_SCHEMAS=		conglomerate.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
