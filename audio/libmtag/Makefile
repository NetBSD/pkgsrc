# $NetBSD: Makefile,v 1.3 2009/12/16 19:54:39 drochner Exp $
#

DISTNAME=	libmtag-0.3.2
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
PKG_DESTDIR_SUPPORT= user-destdir

.include "../../audio/taglib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
