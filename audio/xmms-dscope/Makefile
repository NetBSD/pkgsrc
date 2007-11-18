# $NetBSD: Makefile,v 1.22 2007/11/18 10:23:23 wiz Exp $
#

DISTNAME=	dscope-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://hem.passagen.se/joakime/linuxapp.html
COMMENT=	XMMS plugin for dual scope

USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
