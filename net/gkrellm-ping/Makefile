# $NetBSD: Makefile,v 1.5 2003/05/03 22:20:17 wiz Exp $

DISTNAME=	gkrellmPing-0.2-3
PKGNAME=	gkrellm-ping-0.2.3
PKGREVISION=	2
WRKSRC=		${WRKDIR}/gkrellmPing
CATEGORIES=	net sysutils
MASTER_SITES=	http://gkrellmping.dweb.ro/downloads/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://gkrellmping.dweb.ro/
COMMENT=	gkrellm ping plugin

USE_BUILDLINK2=	# defined
USE_GMAKE=	# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellmPing.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
