# $NetBSD: Makefile,v 1.5 2003/05/02 11:53:40 wiz Exp $

DISTNAME=	gkrellmms-0.5.6
PKGREVISION=	1
PKGNAME=	gkrellm-xmms-0.5.6
WRKSRC=		${WRKDIR}/gkrellmms
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://gkrellm.luon.net/gkrellmms.phtml
COMMENT=	gkrellm xmms plugin

DEPENDS+=       xmms>=1.2.7nb6:../xmms
DEPENDS+=       gkrellm>=1.2.13nb1:../../sysutils/gkrellm

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../mk/bsd.pkg.mk"
