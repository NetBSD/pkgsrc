# $NetBSD: Makefile,v 1.22 2004/03/09 12:47:42 markd Exp $

DISTNAME=	kdesdk-${_KDE_VERSION}
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

CONFLICTS+=	cervisia-[0-9]*
CONFLICTS+=	umbrello-[0-9]*

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/kapptemplate/admin/ltconfig

BUILD_DEPENDS+= qt3-tools>=3.1.1:../../x11/qt3-tools

REPLACE_PERL=	cervisia/change_colors.pl \
		cervisia/move_repositories.pl \
		scripts/cvs2pack \
		scripts/cvsblame \
		scripts/cvscheck \
		scripts/cvslastchange \
		scripts/cxxmetric \
		scripts/extend_dmalloc \
		scripts/extractrc \
		scripts/fixincludes \
		scripts/includemocs \
		scripts/noncvslist

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	# empty
.if ${OPSYS} == "Linux"
PLIST_SRC+=	${PKGDIR}/PLIST.kmtrace
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

.include "../../databases/db4/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
