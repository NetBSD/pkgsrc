# $NetBSD: Makefile,v 1.4 2013/03/16 12:25:48 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gdk3-${VERSION}
COMMENT=		Ruby binding of GDK3
CATEGORIES=		graphics

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gdk3-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gdk3

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf

do-test:
	${RUN} cd ${WRKSRC}/gtk2/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.ruby-gnome2-pango+=	${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}
.include "../../devel/ruby-gnome2-pango/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.4.2
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
