# $NetBSD: Makefile,v 1.2 2003/02/25 11:34:37 salo Exp $
#

DISTNAME=	ifile-1.3.0
CATEGORIES=	mail
MASTER_SITES=	http://savannah.nongnu.org/download/ifile/default.pkg/${PKGVERSION}/

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCHFILES=	ifile-${PKGVERSION}.argp_configure.patch.gz

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://www.nongnu.org/ifile/
COMMENT=	Intelligent mail filtering system

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../mk/bsd.pkg.mk"
