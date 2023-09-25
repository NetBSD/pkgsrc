# $NetBSD: Makefile,v 1.2 2023/09/25 12:12:02 gdt Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs28/:S/-/-nox11-/}
CONFLICTS+=	emacs28-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs28/files
PATCHDIR=	${.CURDIR}/../../editors/emacs28/patches
PKGDIR=		${.CURDIR}/../../editors/emacs28
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs28/distinfo

# minimal emacs without X
CONFIGURE_ARGS+=	--without-all --without-x
# on macOS, nextstep (cocoa) is probed for, even if --without-all is
# given.  Pass it unconditionally, as forcing it off won't hurt on
# not-mac
CONFIGURE_ARGS+=	--without-ns
# but we want to gzip installed files
CONFIGURE_ARGS+=	--with-compress-install

.include "../../editors/emacs28/Makefile.common"
.include "../../mk/bsd.pkg.mk"
