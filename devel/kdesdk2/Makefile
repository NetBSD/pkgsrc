# $NetBSD: Makefile,v 1.12 2004/01/03 18:49:38 reed Exp $

DISTNAME=	kdesdk-2.2.2
PKGREVISION=	4
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+= qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=		# defined
LTCONFIG_OVERRIDE+=	${WRKSRC}/kapptemplate/admin/ltconfig

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	# empty
.if ${OPSYS} == "Linux"
PLIST_SRC+=	${PKGDIR}/PLIST.kmtrace
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

.include "../../databases/db/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
