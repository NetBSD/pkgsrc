# $NetBSD: Makefile,v 1.7 2008/11/15 01:16:49 bjs Exp $
#

PKGNAME=	${DISTNAME:S/d//:C/-/&devel-/}
COMMENT=	Python-based, open-source build tool (development version)

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		scons-[0-9]*

.include "../../devel/scons/Makefile.common"

SCONS_VERSION=		1.1.0.d20081104

.include "../../mk/bsd.pkg.mk"
