# $NetBSD: Makefile,v 1.7 2017/08/16 21:22:11 wiz Exp $
#

DISTNAME=	libmtag-0.3.2
PKGREVISION=	1
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
.include "../../mk/bsd.pkg.mk"
