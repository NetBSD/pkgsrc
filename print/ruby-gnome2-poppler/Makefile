# $NetBSD: Makefile,v 1.2 2007/11/11 23:30:17 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-poppler-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of poppler-glib
CATEGORIES=		print

RUBY_EXTCONF_SUBDIRS=	poppler

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
USE_TOOLS+=		pkg-config
DISTINFO_FILE?=		${.CURDIR}/distinfo

BUILDLINK_API_DEPENDS.poppler-glib+=	poppler-glib>=0.6.0

.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
