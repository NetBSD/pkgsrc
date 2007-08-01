# $NetBSD: Makefile,v 1.18 2007/08/01 20:54:16 joerg Exp $
#

DISTNAME=	cvs2cl-2.59
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.red-bean.com/cvs2cl/
COMMENT=	CVS-log-message-to-ChangeLog conversion script

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_TOOLS+=	perl

CHECK_INTERPRETER_SKIP=	share/cvs/contrib

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/cvs2cl

.include "../../mk/bsd.pkg.mk"
