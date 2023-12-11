# $NetBSD: Makefile,v 1.3 2023/12/11 15:46:10 gdt Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs28/:S/-/-nox11-/}
CONFLICTS+=	emacs28-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs28/files
PATCHDIR=	${.CURDIR}/../../editors/emacs28/patches
PKGDIR=		${.CURDIR}/../../editors/emacs28
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs28/distinfo

# minimal emacs without X, Cocoa, or any other GUI toolkit
CONFIGURE_ARGS+=	--without-all --without-x --without-ns
# but we want to gzip installed files
CONFIGURE_ARGS+=	--with-compress-install

.include "../../editors/emacs28/Makefile.common"
.include "../../mk/bsd.pkg.mk"
