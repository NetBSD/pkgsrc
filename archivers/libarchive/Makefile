# $NetBSD: Makefile,v 1.34 2011/10/26 08:32:50 cheusov Exp $
#

DISTNAME=	libarchive-2.8.4
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libarchive/
COMMENT=	Library to read/create different archive formats

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
