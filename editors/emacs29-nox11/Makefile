# $NetBSD: Makefile,v 1.3 2023/12/11 15:46:10 gdt Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs29/:S/-/-nox11-/}
CONFLICTS+=	emacs29-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs29/files
PATCHDIR=	${.CURDIR}/../../editors/emacs29/patches
PKGDIR=		${.CURDIR}/../../editors/emacs29
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs29/distinfo

# minimal emacs without X, Cocoa, or any other GUI toolkit
CONFIGURE_ARGS+=	--without-all --without-x --without-ns
# but we want to gzip installed files
CONFIGURE_ARGS+=	--with-compress-install

PLIST.nonative=		yes

.include "../../editors/emacs29/Makefile.common"
.include "../../mk/bsd.pkg.mk"
