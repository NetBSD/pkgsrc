# $NetBSD: Makefile,v 1.16 2007/01/20 02:19:40 rillig Exp $
#

DISTNAME=	cvs2cl-2.59
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.red-bean.com/cvs2cl/
COMMENT=	CVS-log-message-to-ChangeLog conversion script

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_TOOLS+=	perl

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/cvs2cl

.include "../../mk/bsd.pkg.mk"
