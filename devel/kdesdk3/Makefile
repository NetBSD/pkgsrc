# $NetBSD: Makefile,v 1.1.1.1 2002/07/17 11:06:47 skrll Exp $

DISTNAME=	kdesdk-3.0.2
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

CONFLICTS=	cervisia-[0-9]*

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK_ONLY=	YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/kapptemplate/admin/ltconfig

BUILD_DEPENDS+= qt3-tools>=3.0.4nb1:../../x11/qt3-tools

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	# empty
.if ${OPSYS} == "Linux"
PLIST_SRC+=	${PKGDIR}/PLIST.kmtrace
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

.include "../../databases/db/buildlink.mk"
.include "../../devel/libtool/buildlink.mk"
.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
