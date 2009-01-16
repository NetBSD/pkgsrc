# $NetBSD: Makefile,v 1.11 2009/01/16 09:18:30 obache Exp $

DISTNAME=	szip-2.1
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.hdfgroup.org/lib-external/szip/2.1/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hdf.ncsa.uiuc.edu/doc_resource/SZIP/
COMMENT=	Extended-Rice lossless compression

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=		szip-license
RESTRICTED=		No permission to redistribute
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DIST_SUBDIR=		${PKGNAME}
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

INSTALLATION_DIRS=	include lib

.include "../../mk/bsd.pkg.mk"
