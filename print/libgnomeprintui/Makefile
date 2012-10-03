# $NetBSD: Makefile,v 1.71.2.1 2012/10/03 12:09:16 spz Exp $
#

DISTNAME=	libgnomeprintui-2.18.6
PKGREVISION=	10
CATEGORIES=	print gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgnomeprintui/2.18/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.levien.com/gnome/print-arch.html
COMMENT=	Graphical library for the GNOME2 Printing Architecture

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake msgfmt pkg-config intltool
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE=	libgnomeprintui/libgnomeprintui-2.2.pc.in

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=	gtkdoc-rebase

BUILDLINK_API_DEPENDS.libgnomeprint+=	libgnomeprint>=2.12.1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
