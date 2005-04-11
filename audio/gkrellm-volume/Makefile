# $NetBSD: Makefile,v 1.16 2005/04/11 21:44:52 tv Exp $

DISTNAME=	gkrellm-volume-2.1.13
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://gkrellm.luon.net/volume.phtml
COMMENT=	Gkrellm2 volume mixer plugin

BUILD_USES_MSGFMT=	YES

USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES
WRKSRC=			${WRKDIR}/gkrellm-volume

MAKE_ENV+=	LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale \
		enable_nls=1

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
