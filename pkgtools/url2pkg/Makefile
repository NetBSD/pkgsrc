# $NetBSD: Makefile,v 1.4 2000/04/01 20:58:44 hubertf Exp $
#

DISTNAME=	url2pkg-1.8
CATEGORIES=	pkgtools sysutils
# The file is under CVS control in othersrc/usr.bin/url2pkg
MASTER_SITES=	http://rfhs8012.fh-regensburg.de/~feyrer/Misc/
EXTRACT_SUFX=	# Nothing

MAINTAINER=	hubertf@netbsd.org

NO_BUILD=	YES
NO_PATCH=	YES
EXTRACT_CMD=	${ECHO_CMD}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} ${LOCALBASE}/bin/${DISTNAME:C/-.*$//}

.include "../../mk/bsd.pkg.mk"
