# $NetBSD: Makefile,v 1.4 2001/10/23 13:14:45 jlam Exp $
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
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/x11.buildlink.mk"
.include "../../audio/xmms/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
