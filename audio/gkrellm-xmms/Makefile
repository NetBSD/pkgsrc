# $NetBSD: Makefile,v 1.11 2004/01/20 12:07:42 agc Exp $

DISTNAME=	gkrellmms-0.5.6
PKGNAME=	gkrellm-xmms-0.5.6
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/gkrellmms.phtml
COMMENT=	gkrellm xmms plugin

WRKSRC=		${WRKDIR}/gkrellmms
USE_BUILDLINK2=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../audio/xmms/buildlink2.mk"
.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
