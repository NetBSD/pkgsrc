# $NetBSD: Makefile,v 1.2 2008/05/25 17:38:37 tnn Exp $

DISTNAME=		compat_headers-0.2
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.pkgsrc.org/
COMMENT=		compatibility headers

NO_CHECKSUM=		yes
GNU_CONFIGURE=		yes
PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SRC+=		${WRKSRC}/PLIST

do-extract:
	cp -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
