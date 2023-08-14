# $NetBSD: Makefile,v 1.2 2023/08/14 05:13:31 wiz Exp $

PKGNAME=	${DISTNAME:S/emacs/emacs29/:S/-/-nox11-/}
CONFLICTS+=	emacs29-[0-9]*

FILESDIR=	${.CURDIR}/../../editors/emacs29/files
PATCHDIR=	${.CURDIR}/../../editors/emacs29/patches
PKGDIR=		${.CURDIR}/../../editors/emacs29
DISTINFO_FILE=	${.CURDIR}/../../editors/emacs29/distinfo

# minimal emacs without X
CONFIGURE_ARGS+=	--without-all --without-x
# but we want to gzip installed files
CONFIGURE_ARGS+=	--with-compress-install

PLIST.nonative=		yes

.include "../../editors/emacs29/Makefile.common"
.include "../../mk/bsd.pkg.mk"
