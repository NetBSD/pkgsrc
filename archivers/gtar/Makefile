# $NetBSD: Makefile,v 1.15.2.2 2002/06/21 23:04:42 jlam Exp $
#

DISTNAME=	gtar-1.12
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The "meta-package" for the GNU tape archiver (tar)

DEPENDS+=	gtar-base-1.12:../../archivers/gtar-base
DEPENDS+=	gtar-info-1.12:../../archivers/gtar-info

USE_BUILDLINK2=	yes

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
