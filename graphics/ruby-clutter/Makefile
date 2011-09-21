# $NetBSD: Makefile,v 1.2 2011/09/21 15:26:46 taca Exp $
#

PKGNAME=	${RUBY_PKGPREFIX}-clutter-${VERSION}
COMMENT=	Ruby binding for Clutter libraries
CATEGORIES=	meta-pkgs

META_PACKAGE=	yes

RUBY_VERSION_SUPPORTED= 18

DEPENDS+=	${RUBY_PKGPREFIX}-clutter-core>=${VERSION}:../../graphics/ruby-clutter-core
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-cairo>=${VERSION}:../../graphics/ruby-clutter-cairo
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-gtk>=${VERSION}:../../graphics/ruby-clutter-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-cairo>=${VERSION}:../../graphics/ruby-clutter-cairo
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-gst>=${VERSION}:../../multimedia/ruby-clutter-gst

.include "Makefile.common"
