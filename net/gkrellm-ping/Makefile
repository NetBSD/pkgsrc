# $NetBSD: Makefile,v 1.10 2004/01/24 14:50:05 grant Exp $

DISTNAME=	gkrellmPing-0.2-3
PKGNAME=	gkrellm-ping-0.2.3
PKGREVISION=	4
CATEGORIES=	net sysutils
MASTER_SITES=	http://gkrellmping.dweb.ro/downloads/

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://gkrellmping.dweb.ro/
COMMENT=	gkrellm ping plugin

WRKSRC=		${WRKDIR}/gkrellmPing
USE_BUILDLINK2=	# defined
USE_GNU_TOOLS+=	make

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellmPing.so ${PREFIX}/lib/gkrellm/plugins/

.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
