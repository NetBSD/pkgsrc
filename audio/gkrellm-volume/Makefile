# $NetBSD: Makefile,v 1.2 2002/07/13 15:38:41 wiz Exp $

DISTNAME=	volume-0.8
PKGNAME=	gkrellm-${DISTNAME}
WRKSRC=		${WRKDIR}/volume
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://gkrellm.luon.net/volume.phtml
COMMENT=	gkrellm volume mixer plugin

DEPENDS+=       gkrellm-1.2.*:../../sysutils/gkrellm

USE_PTHREAD=		native pth
#USE_BUILDLINK_ONLY=	yes

.include "../../graphics/imlib/buildlink.mk"
.include "../../sysutils/gkrellm/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
