# $NetBSD: Makefile,v 1.23 2009/07/08 15:09:19 joerg Exp $
#

DISTNAME=	dscope-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual scope

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES

INSTALLATION_DIRS=	lib/xmms/Visualization

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
