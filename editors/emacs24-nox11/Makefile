# $NetBSD: Makefile,v 1.6 2014/07/09 01:50:44 taca Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs24/:S/-/-nox11-/}
PKGREVISION=	1

CONFLICTS+=	emacs24-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs24/files
PATCHDIR=	${.CURDIR}/../../editors/emacs24/patches
PKGDIR=		${.CURDIR}/../../editors/emacs24

.include "../../editors/emacs24/Makefile.common"

CONFIGURE_ARGS+=	--without-dbus --without-m17n-flt --without-otf \
			--without-rsvg --without-x --without-xft \
			--without-gif --without-jpeg --without-png \
			--without-tiff --without-xpm

.include "../../mk/bsd.pkg.mk"
