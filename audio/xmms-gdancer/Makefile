# $NetBSD: Makefile,v 1.2 2001/08/23 14:07:32 jlam Exp $
#

DISTNAME=	gdancer-0.4.3
PKGNAME=	xmms-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://figz.com/gdancer/files/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://figz.com/gdancer/
COMMENT=	XMMS plugin to animate characters to the beat of the music

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
