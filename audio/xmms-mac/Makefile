# $NetBSD: Makefile,v 1.11 2025/11/17 11:00:24 wiz Exp $
#

DISTNAME=	xmms-mac-0.3.1
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	# http://bsd.cenkes.org/myports/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://sourceforge.net/projects/mac-port/
COMMENT=	XMMS plugin for Monkey's Audio files

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

# needs a bugfix to compile
BUILDLINK_API_DEPENDS.xmms+=	xmms>=1.2.10nb7

.include "../../audio/xmms/buildlink3.mk"
.include "../../audio/mac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
