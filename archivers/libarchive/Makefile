# $NetBSD: Makefile,v 1.36 2012/09/11 19:46:56 asau Exp $
#

DISTNAME=	libarchive-2.8.4
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libarchive/
COMMENT=	Library to read/create different archive formats

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-bsdtar --without-expat --without-xml2 \
			--disable-bsdcpio

do-extract:
	${CP} -r ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS
# workaround for pkg/45491
CONFIGURE_ENV+=	ac_cv_header_ext2fs_ext2_fs_h=no
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
