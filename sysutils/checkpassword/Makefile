# $NetBSD: Makefile,v 1.24 2025/05/22 04:51:30 schmonz Exp $

DISTNAME=		checkpassword-0.90
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://cr.yp.to/checkpwd/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/checkpwd.html
COMMENT=		Simple, uniform password-checking interface to all root applications
LICENSE=		public-domain

FORCE_C_STD=		c89

DJB_ERRNO_FIXUP=	error.h

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checkpassword ${DESTDIR}${PREFIX}/bin

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
