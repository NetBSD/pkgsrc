# $NetBSD: Makefile,v 1.6 2005/04/11 21:44:52 tv Exp $

DISTNAME=	volume-0.8
PKGNAME=	gkrellm-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/volume.phtml
COMMENT=	gkrellm volume mixer plugin

WRKSRC=			${WRKDIR}/volume
PTHREAD_OPTS=		require

.include "../../graphics/imlib/buildlink3.mk"
.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
