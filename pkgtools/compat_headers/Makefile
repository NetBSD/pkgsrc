# $NetBSD: Makefile,v 1.5 2009/05/02 16:21:45 reed Exp $

DISTNAME=		compat_headers-0.2
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		compatibility headers

PREV_PKGPATH=		pkgtools/posix_headers
SUPERSEDES=		posix_headers-[0-9]*

CHECK_PERMS=		no
GNU_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SRC+=		${WRKSRC}/PLIST

do-extract:
	cp -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
