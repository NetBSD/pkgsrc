# $NetBSD: Makefile,v 1.16 2012/09/11 19:47:01 asau Exp $

DISTNAME=	szip-2.1
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.hdfgroup.org/lib-external/szip/2.1/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hdfgroup.org/doc_resource/SZIP/
COMMENT=	Extended-Rice lossless compression
LICENSE=		szip-license

RESTRICTED=		No permission to redistribute
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# pkgrevisions 0, 1, 2 and 3 all have different distfiles
DIST_SUBDIR=		${PKGNAME_NOREV}nb3
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}

INSTALLATION_DIRS=	include lib

.include "../../mk/bsd.pkg.mk"
