# $NetBSD: Makefile,v 1.25 2004/04/20 14:08:39 markd Exp $

DISTNAME=	kdesdk-${_KDE_VERSION}
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

CONFLICTS+=	cervisia-[0-9]*
CONFLICTS+=	umbrello-[0-9]*

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_PERL5=		run

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

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
