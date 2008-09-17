# $NetBSD: Makefile,v 1.6 2008/09/17 00:21:49 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomeprint-${VERSION}
COMMENT=		Ruby binding of libgnomeprint
CATEGORIES=		print

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gnomeprint

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
USE_TOOLS+=		pkg-config

# Need rblibgnomeprintversion.h for build ruby-gnome2-gnomeprintui.
post-install:
	${INSTALL_DATA} ${WRKSRC}/gnomeprint/src/rblibgnomeprintversion.h \
		${DESTDIR}${RUBY_VENDORARCHLIBDIR}

do-test:
	${RUN} cd ${WRKSRC}/gnomeprint/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
