# $NetBSD: Makefile,v 1.1.1.1 2007/02/09 21:21:34 drochner Exp $
#

DISTNAME=	xmms-mac-0.3.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mac-port/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mac-port/
COMMENT=	XMMS plugin for Monkey's Audio files

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c++

# needs a bugfix to compile
BUILDLINK_API_DEPENDS.xmms+=	xmms>=1.2.10nb7

.include "../../audio/xmms/buildlink3.mk"
.include "../../audio/mac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
