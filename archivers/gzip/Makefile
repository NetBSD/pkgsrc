# $NetBSD: Makefile,v 1.5.2.1 2002/05/11 02:08:50 jlam Exp $

DISTNAME=	gzip-1.2.4a
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	The "meta-package" for the GZIP compression utility

DEPENDS+=	gzip-base-1.2.4a:../../archivers/gzip-base
DEPENDS+=	gzip-info-1.2.4a:../../archivers/gzip-info

USE_BUILDLINK2_ONLY=	yes

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
