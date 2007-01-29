# $NetBSD: Makefile,v 1.4 2007/01/29 06:42:34 minskim Exp $
#

PKGNAME=	${RUBY_PKGPREFIX}-gnome2-${VERSION}
COMMENT=	Set of Ruby language bindings for GNOME2
DISTFILES=	# empty
CATEGORIES=	meta-pkgs gnome

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gnome>=${VERSION}:../../x11/ruby-gnome2-gnome
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gnomecanvas>=${VERSION}:../../graphics/ruby-gnome2-gnomecanvas
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-panelapplet>=${VERSION}:../../x11/ruby-gnome2-panelapplet
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:	# empty

.include "../../lang/ruby/rubyversion.mk"
.include "${.CURDIR}/Makefile.common"
