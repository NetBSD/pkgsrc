# $NetBSD: Makefile,v 1.1 2026/08/25 17:23:51 wiz Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs31/:S/-/-nox11-/}

CONFLICTS+=	emacs31-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs31/files
PATCHDIR=	${.CURDIR}/../../editors/emacs31/patches
PKGDIR=		${.CURDIR}/../../editors/emacs31
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs31/distinfo

# minimal emacs without X, Cocoa, or any other GUI toolkit
CONFIGURE_ARGS+=	--without-all --without-x --without-ns
# but we want to gzip installed files and have module support
CONFIGURE_ARGS+=	--with-compress-install
CONFIGURE_ARGS+=	--with-modules

.include "../../editors/emacs31/Makefile.common"
.include "../../mk/bsd.pkg.mk"
