# $NetBSD: Makefile,v 1.3 2012/08/13 06:38:50 wiz Exp $

PKGNAME=	${DISTNAME:S/-/-nox11-/}
PKGREVISION=	2

CONFLICTS+=	emacs-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs24/files
PATCHDIR=	${.CURDIR}/../../editors/emacs24/patches
PKGDIR=		${.CURDIR}/../../editors/emacs24

.include "../../editors/emacs24/Makefile.common"

CONFIGURE_ARGS+=	--without-dbus --without-m17n-flt --without-otf \
			--without-rsvg --without-x --without-xft \
			--without-gif --without-jpeg --without-png \
			--without-tiff --without-xpm

.include "../../mk/bsd.pkg.mk"
