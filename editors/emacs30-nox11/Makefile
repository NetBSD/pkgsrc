# $NetBSD: Makefile,v 1.2 2025/12/24 22:21:00 wiz Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs30/:S/-/-nox11-/}

CONFLICTS+=	emacs30-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs30/files
PATCHDIR=	${.CURDIR}/../../editors/emacs30/patches
PKGDIR=		${.CURDIR}/../../editors/emacs30
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs30/distinfo

# minimal emacs without X, Cocoa, or any other GUI toolkit
CONFIGURE_ARGS+=	--without-all --without-x --without-ns
# but we want to gzip installed files and have module support
CONFIGURE_ARGS+=	--with-compress-install
CONFIGURE_ARGS+=	--with-modules

.include "../../editors/emacs30/Makefile.common"
.include "../../mk/bsd.pkg.mk"
