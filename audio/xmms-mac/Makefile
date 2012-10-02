# $NetBSD: Makefile,v 1.9 2012/10/02 23:48:15 asau Exp $
#

DISTNAME=	xmms-mac-0.3.1
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	# http://bsd.cenkes.org/myports/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://sourceforge.net/projects/mac-port/
COMMENT=	XMMS plugin for Monkey's Audio files

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

# needs a bugfix to compile
BUILDLINK_API_DEPENDS.xmms+=	xmms>=1.2.10nb7

.include "../../audio/xmms/buildlink3.mk"
.include "../../audio/mac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
