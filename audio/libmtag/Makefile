# $NetBSD: Makefile,v 1.9 2024/01/28 13:24:33 wiz Exp $
#

DISTNAME=	libmtag-0.3.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://libmtag.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/libmtag/
COMMENT=	Music tagging library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libmtag.pc.in

.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
