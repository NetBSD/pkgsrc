# $NetBSD: Makefile,v 1.1.1.1 2009/07/07 19:02:02 drochner Exp $
#

DISTNAME=	libmtag-0.3.1
CATEGORIES=	audio
MASTER_SITES=	http://libmtag.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/libmtag/
COMMENT=	Music tagging library

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libmtag.pc.in

.include "../../audio/taglib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
