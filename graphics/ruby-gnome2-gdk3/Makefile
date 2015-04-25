# $NetBSD: Makefile,v 1.16 2015/04/25 14:23:19 tnn Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gdk3-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of GDK3
CATEGORIES=		graphics

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gdk3-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-cairo-gobject>=${VERSION}:../../graphics/ruby-gnome2-cairo-gobject
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
DEPENDS+=		gtk3+>=3.4.2:../../x11/gtk3

RUBY_SETUP_SUBDIRS=	gdk3

USE_RUBY_EXTCONF=	no
USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/gdk3/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
