# $NetBSD: Makefile,v 1.14 2001/02/16 13:15:28 wiz Exp $
#

DISTNAME=	gtar-1.12
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The ''meta-package" for the GNU tape archiver (tar)

DEPENDS+=	gtar-base-1.12:../../archivers/gtar-base
DEPENDS+=	gtar-info-1.12:../../archivers/gtar-info

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
