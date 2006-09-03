# $NetBSD: Makefile,v 1.15 2006/09/03 00:56:28 wiz Exp $
#

DISTNAME=	cvs2cl-2.59
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.red-bean.com/cvs2cl/
COMMENT=	CVS-log-message-to-ChangeLog conversion script

EXTRACT_CMD=	${ECHO}
WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_TOOLS+=	perl

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DISTNAME} \
		${PREFIX}/bin/${DISTNAME:C/-.*$//}

.include "../../mk/bsd.pkg.mk"
