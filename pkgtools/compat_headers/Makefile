# $NetBSD: Makefile,v 1.10 2020/01/26 17:31:59 rillig Exp $

PKGNAME=		compat_headers-0.2
CATEGORIES=		pkgtools

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.pkgsrc.org/
COMMENT=		Compatibility headers

PREV_PKGPATH=		pkgtools/posix_headers
SUPERSEDES=		posix_headers-[0-9]*

CHECK_PERMS=		no
GNU_CONFIGURE=		yes

PLIST_SRC+=		${WRKSRC}/PLIST

do-extract:
	cp -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
