# $NetBSD: Makefile,v 1.6 2003/03/29 12:40:31 jmmv Exp $
#

DISTNAME=	cvs2cl-1.117
WRKSRC=		${WRKDIR}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@netbsd.org
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
