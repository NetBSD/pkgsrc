# $NetBSD: Makefile,v 1.9 2004/02/14 18:26:29 jmmv Exp $
#

DISTNAME=	gtk-doc-1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-doc/1.1/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.gtk.org/rdp/
COMMENT=	Tools for authors of the GTK+ reference documentation

DEPENDS+=	docbook-xml>=4.2nb6:../../textproc/docbook-xml
DEPENDS+=	docbook-xsl>=1.64.1nb3:../../textproc/docbook-xsl
DEPENDS+=	dsssl-docbook-modular-[0-9]*:../../textproc/dsssl-docbook-modular

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
PKGCONFIG_OVERRIDE=	gtk-doc.pc.in
CONFIGURE_ARGS+=	--with-xml-catalog=${XML_DEFAULT_CATALOG}

.include "../../lang/perl5/buildlink2.mk"
.include "../../textproc/jade/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../textproc/xmlcatmgr/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
