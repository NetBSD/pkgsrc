# $NetBSD: Makefile,v 1.5 2006/03/04 21:28:53 jlam Exp $

DISTNAME=	szip-2.0
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/HDF/szip/2.0/src/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hdf.ncsa.uiuc.edu/doc_resource/SZIP/
COMMENT=	Extended-Rice lossless compression

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
LICENSE=		no-commercial-use

INSTALLATION_DIRS=	include lib

.include "../../mk/bsd.pkg.mk"
