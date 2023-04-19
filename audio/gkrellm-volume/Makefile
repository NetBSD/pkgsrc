# $NetBSD: Makefile,v 1.72 2023/04/19 08:09:03 adam Exp $

DISTNAME=	gkrellm-volume-2.1.13
PKGREVISION=	46
CATEGORIES=	audio
MASTER_SITES=	http://gkrellm.luon.net/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://gkrellm.luon.net/volume.phtml
COMMENT=	Gkrellm2 volume mixer plugin
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
WRKSRC=			${WRKDIR}/gkrellm-volume

MAKE_ENV+=	LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale \
		enable_nls=1

INSTALLATION_DIRS+=	lib/gkrellm2/plugins
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			LOCALEDIR=${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale

.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
