# $NetBSD: Makefile,v 1.1.1.1 2002/06/11 22:39:42 wiz Exp $

DISTNAME=	volume-0.8
PKGNAME=	gkrellm-${DISTNAME}
WRKSRC=		${WRKDIR}/volume
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://gkrellm.luon.net/volume.phtml
COMMENT=	gkrellm volume mixer plugin

DEPENDS+=       gkrellm-1.2.*:../../sysutils/gkrellm

USE_PTHREAD=	native pth

.include "../../graphics/imlib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
