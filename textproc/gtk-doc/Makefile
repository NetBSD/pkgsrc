# $NetBSD: Makefile,v 1.18 2005/10/08 17:18:13 jmmv Exp $
#

DISTNAME=	gtk-doc-1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/1.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gtk.org/rdp/
COMMENT=	Tools for authors of the GTK+ reference documentation

DEPENDS+=	docbook-xml>=4.4nb1:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl
DEPENDS+=	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in
CONFIGURE_ARGS+=	--with-xml-catalog=${XML_DEFAULT_CATALOG}
USE_TOOLS+=		perl:run

SGML_CATALOGS=		${PREFIX}/share/sgml/gtk-doc/gtk-doc.cat

.include "../../textproc/jade/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
