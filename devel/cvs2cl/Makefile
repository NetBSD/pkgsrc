# $NetBSD: Makefile,v 1.13 2005/06/17 04:49:46 jlam Exp $
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

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} \
		${PREFIX}/bin/${DISTNAME:C/-.*$//}

.include "../../mk/bsd.pkg.mk"
