# $NetBSD: Makefile,v 1.30 2004/12/10 06:29:31 markd Exp $

DISTNAME=	kdesdk-${_KDE_VERSION}
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

CONFLICTS+=	cervisia-[0-9]*
CONFLICTS+=	umbrello-[0-9]*

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		YES
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		lex
USE_PERL5=		run

REPLACE_PERL=	cervisia/change_colors.pl \
		cervisia/move_repositories.pl \
		kcachegrind/converters/dprof2calltree \
		kcachegrind/converters/memprof2calltree \
		kcachegrind/converters/op2calltree \
		scripts/cvs-clean \
		scripts/cvs2pack \
		scripts/cvsblame \
		scripts/cvscheck \
		scripts/cvslastchange \
		scripts/cxxmetric \
		scripts/extend_dmalloc \
		scripts/extractrc \
		scripts/fixincludes \
		scripts/fixkdeincludes \
		scripts/fixuifiles \
		scripts/includemocs \
		scripts/kdemangen.pl \
		scripts/noncvslist

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	# empty
.if ${OPSYS} == "Linux"
PLIST_SRC+=	${PKGDIR}/PLIST.kmtrace
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
