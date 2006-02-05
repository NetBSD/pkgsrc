# $NetBSD: Makefile,v 1.21 2006/02/05 23:08:17 joerg Exp $
#

DISTNAME=	dspectogram-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.shell.linux.se/bm/index.php?page=xmmsplugin
COMMENT=	XMMS plugin for dual spectogram

USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
