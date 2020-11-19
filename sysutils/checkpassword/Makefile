# $NetBSD: Makefile,v 1.23 2020/11/19 09:35:43 schmonz Exp $
#

DISTNAME=		checkpassword-0.90
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://cr.yp.to/checkpwd/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/checkpwd.html
COMMENT=		Simple, uniform password-checking interface to all root applications
LICENSE=		public-domain

SUBST_CLASSES+=		djberrno

CHECKPASSWORD_BIN=	bin/checkpassword

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checkpassword ${DESTDIR}${PREFIX}/bin

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
