# $NetBSD: Makefile,v 1.9 2003/05/22 03:03:37 markd Exp $

DISTNAME=	kdesdk-3.1.2
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

CONFLICTS=	cervisia-[0-9]*

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/kapptemplate/admin/ltconfig

BUILD_DEPENDS+= qt3-tools>=3.1.1:../../x11/qt3-tools

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	# empty
.if ${OPSYS} == "Linux"
PLIST_SRC+=	${PKGDIR}/PLIST.kmtrace
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

.include "../../databases/db/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
