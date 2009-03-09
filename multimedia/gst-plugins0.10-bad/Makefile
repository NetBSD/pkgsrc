# $NetBSD: Makefile,v 1.5 2009/03/09 11:31:34 jmcneill Exp $
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
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
