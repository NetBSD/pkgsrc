# $NetBSD: Makefile,v 1.5 2002/11/14 23:46:01 jlam Exp $
#

DISTNAME=	cvs2cl-1.117
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.red-bean.com/~kfogel/cvs2cl.shtml
COMMENT=	CVS-log-message-to-ChangeLog conversion script

USE_BUILDLINK2=	YES
NO_BUILD=	YES
EXTRACT_CMD=	${ECHO}
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} \
		${LOCALBASE}/bin/${DISTNAME:C/-.*$//}

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
