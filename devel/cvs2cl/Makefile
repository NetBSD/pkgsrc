# $NetBSD: Makefile,v 1.7 2003/07/17 21:30:03 grant Exp $
#

DISTNAME=	cvs2cl-1.117
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	http://www.red-bean.com/~kfogel/cvs2cl.shtml
COMMENT=	CVS-log-message-to-ChangeLog conversion script

USE_BUILDLINK2=	YES
NO_BUILD=	YES
EXTRACT_CMD=	${ECHO}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} \
		${LOCALBASE}/bin/${DISTNAME:C/-.*$//}

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
