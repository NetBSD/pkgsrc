# $NetBSD: Makefile,v 1.46 2012/01/24 00:28:17 abs Exp $

.include "Makefile.common"

COMMENT=	The GNU database manager
PKGREVISION=	2

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

INFO_FILES=		yes
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		nls

.if ${OPSYS} == "Linux"
PLIST.nls=		yes
.endif

.include "../../mk/bsd.pkg.mk"

