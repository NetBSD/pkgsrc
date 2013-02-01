# $NetBSD: Makefile,v 1.7 2013/02/01 22:21:09 wiz Exp $

DISTNAME=		compat_headers-0.2
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		compatibility headers

PREV_PKGPATH=		pkgtools/posix_headers
SUPERSEDES=		posix_headers-[0-9]*

CHECK_PERMS=		no
GNU_CONFIGURE=		yes

PLIST_SRC+=		${WRKSRC}/PLIST

do-extract:
	cp -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
