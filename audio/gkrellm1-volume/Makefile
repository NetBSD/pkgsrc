# $NetBSD: Makefile,v 1.5 2004/10/03 00:13:05 tv Exp $

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
USE_BUILDLINK3=		yes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
