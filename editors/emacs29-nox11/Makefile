# $NetBSD: Makefile,v 1.5 2024/06/24 00:36:24 gdt Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs29/:S/-/-nox11-/}
#PKGREVISION=	0

CONFLICTS+=	emacs29-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs29/files
PATCHDIR=	${.CURDIR}/../../editors/emacs29/patches
PKGDIR=		${.CURDIR}/../../editors/emacs29
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs29/distinfo

# minimal emacs without X, Cocoa, or any other GUI toolkit
CONFIGURE_ARGS+=	--without-all --without-x --without-ns
# but we want to gzip installed files and have module support
CONFIGURE_ARGS+=	--with-compress-install
CONFIGURE_ARGS+=	--with-modules

PLIST.nonative=		yes

.include "../../editors/emacs29/Makefile.common"
.include "../../mk/bsd.pkg.mk"
