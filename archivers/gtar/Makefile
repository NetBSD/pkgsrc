# $NetBSD: Makefile,v 1.23 2004/03/11 18:03:49 xtraeme Exp $

DISTNAME=	gtar-1.13.25
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The "meta-package" for the GNU tape archiver (tar)

DEPENDS+=	gtar-base-1.13.25nb1:../../archivers/gtar-base
DEPENDS+=	gtar-info-1.13.25:../../archivers/gtar-info

USE_BUILDLINK3=	yes

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
