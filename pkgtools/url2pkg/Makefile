# $NetBSD: Makefile,v 1.1.1.1 1999/05/06 04:24:10 hubertf Exp $
#

DISTNAME=	url2pkg-1.3
CATEGORIES=	pkgtools sysutils
MASTER_SITES=	http://rfhs8012.fh-regensburg.de/~feyrer/Misc/
EXTRACT_SUFX=	# Nothing

MAINTAINER=	hubertf@netbsd.org

NO_BUILD=	YES
NO_PATCH=	YES
EXTRACT_CMD=	${ECHO_CMD}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${LOCALBASE}/bin/${DISTNAME:C/-.*$//}

.include "../../mk/bsd.pkg.mk"
