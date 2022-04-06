# $NetBSD: Makefile,v 1.1 2022/04/06 22:41:03 wiz Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs28/:S/-/-nox11-/}
CONFLICTS+=	emacs28-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs28/files
PATCHDIR=	${.CURDIR}/../../editors/emacs28/patches
PKGDIR=		${.CURDIR}/../../editors/emacs28
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs28/distinfo

# minimal emacs without X
CONFIGURE_ARGS+=	--without-all --without-x
# but we want to gzip installed files
CONFIGURE_ARGS+=	--with-compress-install

.include "../../editors/emacs28/Makefile.common"
.include "../../mk/bsd.pkg.mk"
