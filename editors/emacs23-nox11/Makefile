# $NetBSD: Makefile,v 1.3 2014/07/09 03:19:46 taca Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs23/:S/-/-nox11-/}
PKGREVISION=	3

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
