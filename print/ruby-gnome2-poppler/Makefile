# $NetBSD: Makefile,v 1.4 2008/09/17 00:21:50 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-poppler-${VERSION}
COMMENT=		Ruby binding of poppler-glib
CATEGORIES=		print

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	poppler

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
USE_TOOLS+=		pkg-config

do-test:
	${RUN} cd ${WRKSRC}/poppler/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

BUILDLINK_API_DEPENDS.poppler-glib+=	poppler-glib>=0.6.0

.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
