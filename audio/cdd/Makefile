#	$NetBSD: Makefile,v 1.2 1998/07/17 07:58:38 hubertf Exp $

DISTNAME=	cdd-1.0myc2
PKGNAME=	cdd-1.0myc2
WRKSRC=		${WRKDIR}/cdd
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	thorpej@netbsd.org

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdd ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/stripzeros ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
