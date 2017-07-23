# $NetBSD: Makefile,v 1.3 2017/07/23 18:47:09 dholland Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs25/:S/-/-nox11-/}
PKGREVISION=	1

CONFLICTS+=	emacs25-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs25/files
PATCHDIR=	${.CURDIR}/../../editors/emacs25/patches
PKGDIR=		${.CURDIR}/../../editors/emacs25

.include "../../editors/emacs25/Makefile.common"

CONFIGURE_ARGS+=	--without-dbus --without-m17n-flt --without-otf
CONFIGURE_ARGS+=	--without-rsvg --without-x --without-xft
CONFIGURE_ARGS+=	--without-gif --without-jpeg --without-png
CONFIGURE_ARGS+=	--without-tiff --without-xpm

.include "../../mk/bsd.pkg.mk"
