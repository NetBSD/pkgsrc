# $NetBSD: Makefile,v 1.23 2006/10/04 20:44:20 wiz Exp $
#

DISTNAME=	dspectogram-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hem.passagen.se/joakime/
COMMENT=	XMMS plugin for dual spectogram

USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
