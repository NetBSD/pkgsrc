# $NetBSD: Makefile,v 1.29 2005/05/23 08:11:44 rillig Exp $

DISTNAME=	gtar-1.15.1
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The "meta-package" for the GNU tape archiver (tar)

DEPENDS+=	gtar-base-1.15.1:../../archivers/gtar-base
DEPENDS+=	gtar-info-1.15.1:../../archivers/gtar-info

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
