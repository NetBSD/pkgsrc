# $NetBSD: Makefile,v 1.1.1.1 1999/09/03 06:25:32 sakamoto Exp $
#

DISTNAME=	cvs2cl-download.shtml
PKGNAME=	cvs2cl-1.117
CATEGORIES=	devel
MASTER_SITES=	http://www.red-bean.com/~kfogel/
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.red-bean.com/~kfogel/cvs2cl.shtml

USE_PERL5=	YES
NO_BUILD=	YES
NO_PATCH=	YES
EXTRACT_CMD=	${TAIL} -n +3 ${DOWNLOADED_DISTFILE} > ${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${LOCALBASE}/bin/${DISTNAME:C/-.*$//}

.include "../../mk/bsd.pkg.mk"
