# $NetBSD: Makefile,v 1.6 2018/05/31 01:44:09 gdt Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs25/:S/-/-nox11-/}

CONFLICTS+=	emacs25-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs25/files
PATCHDIR=	${.CURDIR}/../../editors/emacs25/patches
PKGDIR=		${.CURDIR}/../../editors/emacs25

.include "../../editors/emacs25/Makefile.common"

CONFIGURE_ARGS+=	--without-dbus --without-m17n-flt --without-otf
CONFIGURE_ARGS+=	--without-rsvg --without-x --without-xft
CONFIGURE_ARGS+=	--without-gif --without-jpeg --without-png
CONFIGURE_ARGS+=	--without-tiff --without-xpm
CONFIGURE_ARGS+=	--without-ns

.include "../../mk/bsd.pkg.mk"
