# $NetBSD: Makefile,v 1.8 2002/03/13 17:36:50 fredb Exp $

DISTNAME=	kdesdk-2.2.2
PKGREVISION=	1
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+= qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/kapptemplate/admin/ltconfig

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	# empty
.if ${OPSYS} == "Linux"
PLIST_SRC+=	${PKGDIR}/PLIST.kmtrace
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

.include "../../databases/db/buildlink.mk"
.include "../../devel/libtool/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
