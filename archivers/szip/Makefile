# $NetBSD: Makefile,v 1.2 2004/07/28 02:47:35 minskim Exp $
#

DISTNAME=		szip1.1
PKGNAME=		szip-1.1
CATEGORIES=		archivers
MASTER_SITES=		ftp://ftp.ncsa.uiuc.edu/HDF/szip/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://hdf.ncsa.uiuc.edu/doc_resource/SZIP/
COMMENT=		Extended-Rice lossless compression

PKG_INSTALLATION_TYPES=	overwrite pkgviews

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
LICENSE=		no-commercial-use

INSTALLATION_DIRS=	include lib

.include "../../mk/bsd.pkg.mk"
