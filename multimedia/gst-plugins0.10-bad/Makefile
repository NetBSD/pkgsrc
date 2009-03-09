# $NetBSD: Makefile,v 1.7 2009/03/09 16:02:07 drochner Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

.include "Makefile.common"

PKGREVISION=		2
COMMENT+=		bad plugins

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	x86
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.x86=	yes
.endif

# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
