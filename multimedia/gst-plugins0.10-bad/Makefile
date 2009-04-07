# $NetBSD: Makefile,v 1.8 2009/04/07 09:53:54 drochner Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

.include "Makefile.common"

COMMENT+=		bad plugins

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	x86
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.x86=	yes
.endif

# bzip2 is likely present anyway, make it default
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
