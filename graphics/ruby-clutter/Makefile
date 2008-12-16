# $NetBSD: Makefile,v 1.1.1.1 2008/12/16 12:22:38 obache Exp $
#

PKGNAME=	${RUBY_PKGPREFIX}-clutter-${VERSION}
COMMENT=	Ruby binding for Clutter libraries
CATEGORIES=	meta-pkgs

META_PACKAGE=	yes

DEPENDS+=	${RUBY_PKGPREFIX}-clutter-core>=${VERSION}:../../graphics/ruby-clutter-core
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-cairo>=${VERSION}:../../graphics/ruby-clutter-cairo
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-gtk>=${VERSION}:../../graphics/ruby-clutter-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-cairo>=${VERSION}:../../graphics/ruby-clutter-cairo
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-gst>=${VERSION}:../../multimedia/ruby-clutter-gst

.include "Makefile.common"
