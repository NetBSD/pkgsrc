# $NetBSD: Makefile,v 1.10 2003/07/17 21:24:03 grant Exp $
#

DISTNAME=	gdancer-0.4.3
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://figz.com/gdancer/files/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://figz.com/gdancer/
COMMENT=	XMMS plugin to animate characters to the beat of the music

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
