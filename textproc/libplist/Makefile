# $NetBSD: Makefile,v 1.1.1.1 2011/11/21 18:51:37 shattered Exp $
#

DISTNAME=	libplist-1.3
CATEGORIES=	textproc
MASTER_SITES=	http://github.com/downloads/JonathanBeck/libplist/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libimobiledevice.org/
COMMENT=	Handle Apple Binary and XML Property Lists
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libplist++.pc.in
PKGCONFIG_OVERRIDE+=	libplist.pc.in
PY_PATCHPLIST=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
