# $NetBSD: Makefile,v 1.9 2003/06/02 01:21:48 jschauma Exp $
#

DISTNAME=	gzip-1.2.4a
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	The "meta-package" for the GZIP compression utility

DEPENDS+=	gzip-base-1.2.4anb1:../../archivers/gzip-base
DEPENDS+=	gzip-info-1.2.4a:../../archivers/gzip-info

USE_BUILDLINK2=	YES

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
