# $NetBSD: Makefile,v 1.17 2017/01/09 04:01:32 schmonz Exp $
#

DISTNAME=		checkpassword-0.90
CATEGORIES=		sysutils
MASTER_SITES=		http://cr.yp.to/checkpwd/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/checkpwd.html
COMMENT=		Simple, uniform password-checking interface to all root applications

DJB_RESTRICTED=		YES

CHECKPASSWORD_BIN=	bin/checkpassword

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checkpassword ${DESTDIR}${PREFIX}/bin

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
