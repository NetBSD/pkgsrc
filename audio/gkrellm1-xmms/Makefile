# $NetBSD: Makefile,v 1.8 2007/02/22 19:01:13 wiz Exp $

DISTNAME=	gkrellmms-0.5.6
PKGNAME=	gkrellm-xmms-0.5.6
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/gkrellmms.phtml
COMMENT=	GKrellM xmms plugin

WRKSRC=		${WRKDIR}/gkrellmms

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../audio/xmms/buildlink3.mk"
.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
