# $NetBSD: Makefile,v 1.3 2002/08/01 05:48:03 jlam Exp $

DISTNAME=	volume-0.8
PKGNAME=	gkrellm-${DISTNAME}
WRKSRC=		${WRKDIR}/volume
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://gkrellm.luon.net/volume.phtml
COMMENT=	gkrellm volume mixer plugin

DEPENDS+=       gkrellm-1.2.*:../../sysutils/gkrellm

PTHREAD_OPTS=		require
#USE_BUILDLINK_ONLY=	yes

.include "../../graphics/imlib/buildlink.mk"
.include "../../sysutils/gkrellm/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
