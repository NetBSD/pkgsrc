# $NetBSD: Makefile,v 1.7 2003/05/02 11:53:51 wiz Exp $
#

DISTNAME=	gdancer-0.4.3
PKGREVISION=	1
PKGNAME=	xmms-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://figz.com/gdancer/files/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://figz.com/gdancer/
COMMENT=	XMMS plugin to animate characters to the beat of the music

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
