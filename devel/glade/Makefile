# $NetBSD: Makefile,v 1.100 2020/11/05 09:06:46 ryoon Exp $

DISTNAME=		glade-3.36.0
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glade/3.36/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://glade.gnome.org/
COMMENT=		User interface builder for the GTK3+ toolkit
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		itstool-[0-9]*:../../textproc/itstool
TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config intltool gmake msgfmt

# Requires --xml in msgfmt.
_TOOLS_USE_PKGSRC.msgfmt=	yes

PKGCONFIG_OVERRIDE+=	data/gladeui-2.0.pc.in

.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
