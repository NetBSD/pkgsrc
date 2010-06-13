# $NetBSD: Makefile,v 1.9 2010/06/13 22:45:17 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-poppler-${VERSION}
COMMENT=		Ruby binding of poppler-glib
PKGREVISION=		2
CATEGORIES=		print

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	poppler

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
USE_TOOLS+=		pkg-config

do-test:
	${RUN} cd ${WRKSRC}/poppler/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../graphics/ruby-rcairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler-glib+=     poppler-glib>=0.8.0
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
