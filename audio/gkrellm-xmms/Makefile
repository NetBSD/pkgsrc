# $NetBSD: Makefile,v 1.3 2002/03/13 17:36:36 fredb Exp $

DISTNAME=	gkrellmms-0.5.5
PKGNAME=	gkrellm-xmms-0.5.5
PKGREVISION=	1
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
