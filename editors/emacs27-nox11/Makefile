# $NetBSD: Makefile,v 1.1 2020/08/12 14:17:52 ryoon Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs27/:S/-/-nox11-/}
CONFLICTS+=	emacs27-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs27/files
PATCHDIR=	${.CURDIR}/../../editors/emacs27/patches
PKGDIR=		${.CURDIR}/../../editors/emacs27
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs27/distinfo

.include "../../editors/emacs27/Makefile.common"

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
