# $NetBSD: Makefile,v 1.21 2003/06/02 01:21:49 jschauma Exp $

DISTNAME=	gtar-1.13.25
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The "meta-package" for the GNU tape archiver (tar)

DEPENDS+=	gtar-base-1.13.25nb1:../../archivers/gtar-base
DEPENDS+=	gtar-info-1.13.25:../../archivers/gtar-info

USE_BUILDLINK2=	yes

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
