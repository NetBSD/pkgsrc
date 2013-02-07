# $NetBSD: Makefile,v 1.17 2013/02/07 13:41:55 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-atk-${VERSION}
COMMENT=		Ruby binding of ATK-1.0.x or later
CATEGORIES=		devel

CONFLICTS+=		ruby-gnome2-atk-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-atk-[0-9]*

RUBY_EXTCONF_SUBDIRS=	atk

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
