# $NetBSD: Makefile,v 1.2 2001/11/01 15:28:44 damon Exp $

DISTNAME=	gkrellmms-0.5.5
PKGNAME=	gkrellm-xmms-0.5.5
WRKSRC=		${WRKDIR}/gkrellmms
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://gkrellm.luon.net/gkrellmms.phtml
COMMENT=	gkrellm xmms plugin

DEPENDS+=       xmms>=1.2.5:../xmms
DEPENDS+=       gkrellm-1.2.*:../../sysutils/gkrellm

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../mk/bsd.pkg.mk"
