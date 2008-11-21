# $NetBSD: Makefile,v 1.8 2008/11/21 09:47:39 tnn Exp $
#

PKGNAME=	${DISTNAME:S/d//:C/-/&devel-/}
COMMENT=	Python-based, open-source build tool (development version)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		scons-[0-9]*

.include "../../devel/scons/Makefile.common"

SCONS_VERSION=		1.1.0.d20081104
PKGREVISION=		1

.include "../../mk/bsd.pkg.mk"
