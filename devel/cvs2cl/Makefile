# $NetBSD: Makefile,v 1.20 2008/03/03 17:45:34 jlam Exp $
#

DISTNAME=	cvs2cl-2.59
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.red-bean.com/cvs2cl/
COMMENT=	CVS-log-message-to-ChangeLog conversion script

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_TOOLS+=	perl

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/bin/cvs2cl

.include "../../mk/bsd.pkg.mk"
