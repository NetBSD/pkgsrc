# $NetBSD: Makefile,v 1.9 2004/04/25 05:30:56 snj Exp $
#

DISTNAME=	cvs2cl-1.117
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.red-bean.com/~kfogel/cvs2cl.shtml
COMMENT=	CVS-log-message-to-ChangeLog conversion script

EXTRACT_CMD=	${ECHO}
WRKSRC=		${WRKDIR}
NO_BUILDLINK=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_PERL5=	# defined

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} \
		${LOCALBASE}/bin/${DISTNAME:C/-.*$//}

.include "../../mk/bsd.pkg.mk"
