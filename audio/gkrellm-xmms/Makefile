# $NetBSD: Makefile,v 1.21 2005/12/05 20:49:48 rillig Exp $
#

DISTNAME=	gkrellmms-2.1.20
PKGNAME=	${DISTNAME:S/mms/m-xmms/}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/gkrellmms.phtml
COMMENT=	GKrellM2 plugin to remotely control XMMS

USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	YES
BUILD_USES_MSGFMT=	YES

BUILDLINK_DEPENDS.gkrellm+=	gkrellm>=2.2.0

WRKSRC=		${WRKDIR}/gkrellmms
MAKE_ENV+=	LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale \
		enable_nls=1

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
