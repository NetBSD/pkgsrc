# $NetBSD: Makefile,v 1.4 2001/11/28 05:20:47 jlam Exp $
#

DISTNAME=	cvs2cl-1.117
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.red-bean.com/~kfogel/cvs2cl.shtml
COMMENT=	CVS-log-message-to-ChangeLog conversion script

USE_BUILDLINK_ONLY=	YES
NO_BUILD=		YES
EXTRACT_CMD=		${ECHO}
WRKSRC=			${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} \
		${LOCALBASE}/bin/${DISTNAME:C/-.*$//}

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
