# $NetBSD: Makefile,v 1.36 2012/08/13 06:53:06 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}
PKGREVISION=	1

CONFLICTS+=	emacs-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs/files
PATCHDIR=	${.CURDIR}/../../editors/emacs/patches
PKGDIR=		${.CURDIR}/../../editors/emacs

.include "../../editors/emacs/Makefile.common"

CONFIGURE_ARGS+=	--without-dbus --without-m17n-flt --without-otf \
			--without-rsvg --without-x --without-xft \
			--without-gif --without-jpeg --without-png \
			--without-tiff --without-xpm

.include "../../mk/bsd.pkg.mk"
