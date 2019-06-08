# $NetBSD: Makefile,v 1.3 2019/06/08 10:40:54 rillig Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs26/:S/-/-nox11-/}
CONFLICTS+=	emacs26-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs26/files
PATCHDIR=	${.CURDIR}/../../editors/emacs26/patches
PKGDIR=		${.CURDIR}/../../editors/emacs26
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs26/distinfo

.include "../../editors/emacs26/Makefile.common"

CONFIGURE_ARGS+=	--without-dbus
CONFIGURE_ARGS+=	--without-xml2
CONFIGURE_ARGS+=	--without-gnutls
CONFIGURE_ARGS+=	--without-rsvg
CONFIGURE_ARGS+=	--without-gconf
CONFIGURE_ARGS+=	--without-imagemagick
CONFIGURE_ARGS+=	--without-xaw3d
CONFIGURE_ARGS+=	--without-xft --without-libotf --without-m17n-flt
CONFIGURE_ARGS+=	--without-ns

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-gif
CONFIGURE_ARGS+=	--without-png

.include "../../mk/bsd.pkg.mk"
