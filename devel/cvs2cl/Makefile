# $NetBSD: Makefile,v 1.32 2022/06/28 11:31:41 wiz Exp $

DISTNAME=	cvs2cl-2.59
PKGREVISION=	10
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# Nothing

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.red-bean.com/cvs2cl/
COMMENT=	CVS-log-message-to-ChangeLog conversion script

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_TOOLS+=	perl

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${DESTDIR}${PREFIX}/bin/cvs2cl

.include "../../mk/bsd.pkg.mk"
