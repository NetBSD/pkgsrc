# $NetBSD: Makefile,v 1.29 2004/01/20 12:23:58 agc Exp $
#

DISTNAME=	url2pkg-1.24
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	# Nothing
DISTFILES=	# Nothing

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	# Nothing
COMMENT=	Tool to automate initial steps in building a package

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
EXTRACT_CMD=	${ECHO}

do-build:
	${SED} -e 's|@MAKE@|${MAKE}|g'		\
	< ${FILESDIR}/url2pkg > ${WRKSRC}/url2pkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/url2pkg ${PREFIX}/bin/url2pkg
	${INSTALL_MAN} ${FILESDIR}/url2pkg.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
