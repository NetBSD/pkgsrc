# $NetBSD: Makefile,v 1.3 2008/05/28 13:40:59 tnn Exp $

DISTNAME=		compat_headers-0.2
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		compatibility headers

NO_CHECKSUM=		yes
CHECK_PERMS=		no
GNU_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SRC+=		${WRKSRC}/PLIST

do-extract:
	cp -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
