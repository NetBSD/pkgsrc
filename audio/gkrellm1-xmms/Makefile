# $NetBSD: Makefile,v 1.4 2004/10/03 00:13:05 tv Exp $

DISTNAME=	gkrellmms-0.5.6
PKGNAME=	gkrellm-xmms-0.5.6
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/gkrellmms.phtml
COMMENT=	gkrellm xmms plugin

WRKSRC=		${WRKDIR}/gkrellmms
USE_BUILDLINK3=	YES

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../audio/xmms/buildlink3.mk"
.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
