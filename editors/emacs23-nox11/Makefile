# $NetBSD: Makefile,v 1.2 2013/02/23 23:49:35 dholland Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs23/:S/-/-nox11-/}
PKGREVISION=	2

CONFLICTS+=	emacs23-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs23/files
PATCHDIR=	${.CURDIR}/../../editors/emacs23/patches
PKGDIR=		${.CURDIR}/../../editors/emacs23

.include "../../editors/emacs23/Makefile.common"

CONFIGURE_ARGS+=	--without-dbus --without-m17n-flt --without-otf \
			--without-rsvg --without-x --without-xft \
			--without-gif --without-jpeg --without-png \
			--without-tiff --without-xpm

.include "../../mk/bsd.pkg.mk"
