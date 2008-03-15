# $NetBSD: Makefile,v 1.23 2008/03/15 11:05:29 joerg Exp $
#

DISTNAME=	libarchive-2.4.14
CATEGORIES=	archivers
MASTER_SITES=	http://people.freebsd.org/~kientzle/libarchive/src/
DISTFILES=	# empty

NO_CHECKSUM=	yes

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://people.freebsd.org/~kientzle/libarchive/
COMMENT=	Library to read/create different archive formats

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-bsdtar

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
