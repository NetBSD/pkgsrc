# $NetBSD: Makefile,v 1.11 2005/04/11 21:45:19 tv Exp $
#

DISTNAME=	cvs2cl-2.58
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.red-bean.com/cvs2cl/
COMMENT=	CVS-log-message-to-ChangeLog conversion script

EXTRACT_CMD=	${ECHO}
WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_PERL5=	# defined

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} \
		${LOCALBASE}/bin/${DISTNAME:C/-.*$//}

.include "../../mk/bsd.pkg.mk"
