# $NetBSD: Makefile,v 1.16 2004/02/09 12:38:58 jmmv Exp $
#

DISTNAME=	conglomerate-0.7.11
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=conglomerate/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.conglomerate.org/
COMMENT=	XML editor for GNOME2

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs
DEPENDS+=		docbook-xsl>=1.64.1:../../textproc/docbook-xsl
DEPENDS+=		docbook-xml>=4.2nb6:../../textproc/docbook-xml

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		yes
USE_PKGLOCALEDIR=	yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-printing
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

GCONF2_SCHEMAS=		conglomerate.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtksourceview/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
