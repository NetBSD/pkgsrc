# $NetBSD: Makefile,v 1.2 2001/11/01 15:34:28 damon Exp $

DISTNAME=	gkrellmPing-0.2-3
PKGNAME=	gkrellm-ping-0.2.3
WRKSRC=		${WRKDIR}/gkrellmPing
CATEGORIES=	net sysutils
MASTER_SITES=	http://gkrellmping.dweb.ro/downloads/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://gkrellmping.dweb.ro/
COMMENT=	gkrellm ping plugin

DEPENDS+=       gkrellm-1.2.*:../../sysutils/gkrellm

USE_GMAKE=	#defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellmPing.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../mk/bsd.pkg.mk"
