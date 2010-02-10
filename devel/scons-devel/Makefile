# $NetBSD: Makefile,v 1.10 2010/02/10 19:17:36 joerg Exp $
#

PKGNAME=	${DISTNAME:S/d//:C/-/&devel-/}
COMMENT=	Python-based, open-source build tool (development version)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		scons-[0-9]*

.include "../../devel/scons/Makefile.common"

SCONS_VERSION=		1.1.0.d20081104
PKGREVISION=		3

.include "../../mk/bsd.pkg.mk"
