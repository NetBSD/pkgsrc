# $NetBSD: Makefile,v 1.12 2004/02/24 22:46:34 cube Exp $
#

DISTNAME=	gkrellmms-2.1.14
PKGNAME=	${DISTNAME:S/mms/m-xmms/}
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/gkrellmms.phtml
COMMENT=	GKrellM2 plugin to remotely control XMMS

WRKSRC=			${WRKDIR}/gkrellmms
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES
BUILD_USES_MSGFMT=	YES

MAKE_ENV+=	LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale \
		enable_nls=1

.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
