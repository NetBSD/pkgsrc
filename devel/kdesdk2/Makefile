# $NetBSD: Makefile,v 1.17 2004/10/15 11:54:10 tv Exp $

DISTNAME=	kdesdk-2.2.2
PKGREVISION=	8
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+= qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK3=		yes
LTCONFIG_OVERRIDE+=	${WRKSRC}/kapptemplate/admin/ltconfig

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	# empty
.if ${OPSYS} == "Linux"
PLIST_SRC+=	${PKGDIR}/PLIST.kmtrace
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

.include "../../databases/db/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
