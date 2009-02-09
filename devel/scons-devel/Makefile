# $NetBSD: Makefile,v 1.9 2009/02/09 22:56:23 joerg Exp $
#

PKGNAME=	${DISTNAME:S/d//:C/-/&devel-/}
COMMENT=	Python-based, open-source build tool (development version)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		scons-[0-9]*

.include "../../devel/scons/Makefile.common"

SCONS_VERSION=		1.1.0.d20081104
PKGREVISION=		2

.include "../../mk/bsd.pkg.mk"
