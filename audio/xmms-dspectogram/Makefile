# $NetBSD: Makefile,v 1.24 2009/07/08 15:05:57 joerg Exp $
#

DISTNAME=	dspectogram-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hem.passagen.se/joakime/
COMMENT=	XMMS plugin for dual spectogram

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES

INSTALLATION_DIRS=	lib/xmms/Visualization

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
