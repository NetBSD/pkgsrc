# $NetBSD: Makefile,v 1.5 2023/12/11 15:46:09 gdt Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs27/:S/-/-nox11-/}
CONFLICTS+=	emacs27-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs27/files
PATCHDIR=	${.CURDIR}/../../editors/emacs27/patches
PKGDIR=		${.CURDIR}/../../editors/emacs27
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs27/distinfo

# minimal emacs without X, Cocoa, or any other GUI toolkit
CONFIGURE_ARGS+=	--without-all --without-x --without-ns
# but we want to gzip installed files
CONFIGURE_ARGS+=	--with-compress-install

.include "../../editors/emacs27/Makefile.common"
.include "../../mk/bsd.pkg.mk"
