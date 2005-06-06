# $NetBSD: Makefile,v 1.38 2005/06/06 18:37:22 jmmv Exp $
#

DISTNAME=		libglade-2.5.1
PKGNAME=		${DISTNAME:S/libglade/libglade2/}
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libglade/2.5/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Runtime interpreter for GLADE GUI files (v2)

BUILD_USES_MSGFMT=	YES

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libglade-2.0.pc.in

CONFIGURE_ARGS+=	--with-html-dir="${PREFIX}/share/doc/html"
CONFIGURE_ARGS+=	--without-xml-catalog

XML_ENTRIES=	system http://glade.gnome.org/glade-2.0.dtd \
		${PREFIX}/share/xml/libglade/glade-2.0.dtd

BUILDLINK_DEPENDS.atk+=		atk>=1.9.0
BUILDLINK_DEPENDS.glib2+=	glib2>=2.6.0
BUILDLINK_DEPENDS.gtk2+=	gtk2+>=2.6.0

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/libglade/2.0

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
