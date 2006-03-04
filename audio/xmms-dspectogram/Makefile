# $NetBSD: Makefile,v 1.22 2006/03/04 21:28:59 jlam Exp $
#

DISTNAME=	dspectogram-1.2
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://hem.passagen.se/joakime/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.shell.linux.se/bm/index.php?page=xmmsplugin
COMMENT=	XMMS plugin for dual spectogram

USE_LIBTOOL=		YES

pre-build:
	cd ${WRKSRC} ; ${MAKE} clean

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
