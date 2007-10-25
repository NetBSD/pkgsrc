# $NetBSD: Makefile,v 1.18 2007/10/25 22:00:39 jlam Exp $
#

DISTNAME=	gzip-1.2.4b
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gzip/gzip.html
COMMENT=	The "meta-package" for the GZIP compression utility

DEPENDS+=	gzip-base-1.2.4b{,nb[0-9]*}:../../archivers/gzip-base
DEPENDS+=	gzip-info-1.2.4a{,nb[0-9]*}:../../archivers/gzip-info

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
PLIST_SRC=	# empty (meta-package)

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
