# $NetBSD: Makefile,v 1.11 2004/04/26 10:34:09 recht Exp $
#

DISTNAME=	gtk-doc-1.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/1.2/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.gtk.org/rdp/
COMMENT=	Tools for authors of the GTK+ reference documentation

DEPENDS+=	docbook-xml>=4.2nb6:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.64.1nb3:../../textproc/docbook-xsl
DEPENDS+=	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		yes
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in
CONFIGURE_ARGS+=	--with-xml-catalog=${XML_DEFAULT_CATALOG}

SGML_CATALOGS=		${PREFIX}/share/sgml/gtk-doc/gtk-doc.cat

.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/jade/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
