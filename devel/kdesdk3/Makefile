# $NetBSD: Makefile,v 1.31 2005/03/23 22:33:47 markd Exp $

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
		cervisia/cervisia-change_repos_list.pl \
		cervisia/cervisia-normalize_cvsroot.pl \
		kapptemplate/admin/am_edit \
		kapptemplate/admin/bcheck.pl \
		kapptemplate/admin/cvs-clean.pl \
		kapptemplate/admin/debianrules \
		kapptemplate/admin/nmcheck \
		kcachegrind/converters/dprof2calltree \
		kcachegrind/converters/memprof2calltree \
		kcachegrind/converters/op2calltree \
		scripts/authors2xml.pl \
		scripts/check_licenses \
		scripts/colorcvs \
		scripts/cvs-clean \
		scripts/cvsblame \
		scripts/cvscheck \
		scripts/cvslastchange \
		scripts/cvslastreferenced \
		scripts/cxxmetric \
		scripts/extend_dmalloc \
		scripts/extractattr \
		scripts/extractrc \
		scripts/fixheaders \
		scripts/fixkdeincludes \
		scripts/fixuifiles \
		scripts/includemocs \
		scripts/kde-spellcheck.pl \
		scripts/kdemangen.pl \
		scripts/licensecheck \
		scripts/noncvslist \
		scripts/png2mng.pl \
		scripts/rc2kcfgxt.pl

REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	/bin/bash
_REPLACE.bash.new=	/bin/sh
_REPLACE_FILES.bash=	scripts/cvs2dist scripts/makeobj \
		scripts/package_crystalsvg

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
