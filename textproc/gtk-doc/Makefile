# $NetBSD: Makefile,v 1.16 2005/04/30 19:18:25 jmmv Exp $
#

DISTNAME=	gtk-doc-1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/1.3/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gtk.org/rdp/
COMMENT=	Tools for authors of the GTK+ reference documentation

DEPENDS+=	docbook-xml>=4.2nb6:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.68.1:../../textproc/docbook-xsl
DEPENDS+=	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in
CONFIGURE_ARGS+=	--with-xml-catalog=${XML_DEFAULT_CATALOG}

SGML_CATALOGS=		${PREFIX}/share/sgml/gtk-doc/gtk-doc.cat

.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/jade/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
