# $NetBSD: Makefile,v 1.15.8.1 2002/12/22 08:29:18 agc Exp $
#

DISTNAME=	gtar-1.13.25
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The "meta-package" for the GNU tape archiver (tar)

DEPENDS+=	gtar-base-1.13.25:../../archivers/gtar-base
DEPENDS+=	gtar-info-1.13.25:../../archivers/gtar-info

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
