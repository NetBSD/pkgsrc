# $NetBSD: Makefile,v 1.12 2004/04/17 20:46:28 zuntum Exp $
#

DISTNAME=	gdancer-0.4.3
PKGNAME=	xmms-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://figz.com/gdancer/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://figz.com/gdancer/
COMMENT=	XMMS plugin to animate characters to the beat of the music

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
