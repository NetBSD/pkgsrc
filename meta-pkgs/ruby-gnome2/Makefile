# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:21 wiz Exp $
#

PKGNAME=	ruby-gnome2-${VERSION}
COMMENT=	Set of Ruby language bindings for GNOME2
DISTFILES=	# empty
PKGREVISION=	1
CATEGORIES=	meta-pkgs gnome

DEPENDS+=	ruby-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=	ruby-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
DEPENDS+=	ruby-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=	ruby-gnome2-gnome>=${VERSION}:../../x11/ruby-gnome2-gnome
DEPENDS+=	ruby-gnome2-gnomecanvas>=${VERSION}:../../graphics/ruby-gnome2-gnomecanvas
DEPENDS+=	ruby-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
DEPENDS+=	ruby-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
DEPENDS+=	ruby-gnome2-panelapplet>=${VERSION}:../../x11/ruby-gnome2-panelapplet
DEPENDS+=	ruby-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "${.CURDIR}/Makefile.common"
