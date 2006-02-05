# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:08 joerg Exp $

DISTNAME=	volume-0.8
PKGNAME=	gkrellm-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/volume.phtml
COMMENT=	gkrellm volume mixer plugin

WRKSRC=			${WRKDIR}/volume
PTHREAD_OPTS=		require

.include "../../graphics/imlib/buildlink3.mk"
.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
