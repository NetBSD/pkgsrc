# $NetBSD: Makefile,v 1.4 2004/03/18 15:33:21 cube Exp $

DISTNAME=	volume-0.8
PKGNAME=	gkrellm-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/volume.phtml
COMMENT=	gkrellm volume mixer plugin

WRKSRC=			${WRKDIR}/volume
PTHREAD_OPTS=		require
USE_BUILDLINK3=		yes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
