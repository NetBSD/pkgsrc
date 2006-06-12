# $NetBSD: Makefile,v 1.43 2006/06/12 17:02:23 reed Exp $
#

DISTNAME=	url2pkg-1.34
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	# Nothing
COMMENT=	Tool to automate initial steps in building a package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
USE_LANGUAGES=	# empty

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-build:
	${SED} -e 's|@MAKE@|${MAKE}|g'		\
	< ${FILESDIR}/url2pkg > ${WRKSRC}/url2pkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/url2pkg ${PREFIX}/bin/url2pkg
	${INSTALL_MAN} ${FILESDIR}/url2pkg.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
