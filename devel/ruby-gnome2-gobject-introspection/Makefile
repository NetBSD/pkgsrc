# $NetBSD: Makefile,v 1.1 2013/02/07 13:41:55 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection-${VERSION}
COMMENT=		Ruby binding of Gobject Introspection
CATEGORIES=		devel

CONFLICTS+=		ruby-gnome2-gobject-introspection-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-gobject-introspection-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gobject-introspection

do-test:
	${RUN} cd ${WRKSRC}/gobject-introspection/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.32.1
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
