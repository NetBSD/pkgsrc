# $NetBSD: Makefile,v 1.8 2003/07/17 21:22:13 grant Exp $

DISTNAME=	volume-0.8
PKGNAME=	gkrellm-${DISTNAME}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/volume
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/volume.phtml
COMMENT=	gkrellm volume mixer plugin

PTHREAD_OPTS=		require
USE_BUILDLINK2=		yes

.include "../../graphics/imlib/buildlink2.mk"
.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
