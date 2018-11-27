# $NetBSD: Makefile,v 1.18 2018/11/27 14:40:25 bsiegert Exp $

DISTNAME=	gspell-1.4.2
PKGREVISION=	9
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gspell/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Projects/gspell
COMMENT=	Spell checking API for GTK+ applications
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	gspell.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
