# $NetBSD: Makefile,v 1.38 2005/09/28 19:47:50 adam Exp $

DISTNAME=	kdesdk-${_KDE_VERSION}
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

CONFLICTS+=	cervisia-[0-9]*
CONFLICTS+=	umbrello-[0-9]*

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		lex perl:run

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

PKG_OPTIONS_VAR=	PKG_OPTIONS.kdesdk
PKG_SUPPORTED_OPTIONS=	svn
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msvn)
.include "../../devel/subversion/buildlink3.mk"
CONFIGURE_ARGS+=	--with-svn-include="${BUILDLINK_PREFIX.subversion-base}/include"
CONFIGURE_ARGS+=	--with-svn-lib="${BUILDLINK_PREFIX.subversion-base}/lib"
PLIST_SUBST+=		HAVE_SVN=""
.else
PLIST_SUBST+=		HAVE_SVN="@comment "
.endif

# a fix for qt-3.3.5, please remove if qt-3.3.6 (or newer) solves the problem
SUBST_CLASSES+=		hints
SUBST_STAGE.hints=	post-patch
SUBST_MESSAGE.hints=	"Fix includehints."
SUBST_FILES.hints=	umbrello/umbrello/dialogs/codevieweroptionsbase.ui
SUBST_FILTER_CMD.hints=	${GREP} -v includehint

# Makefile{,.am,.in} weren't supposed to be installed so clean up
post-install:
	${RM} ${KDEDIR}/share/kde/apps/kapptemplate/admin/Makefile
	${RM} ${KDEDIR}/share/kde/apps/kapptemplate/admin/Makefile.am
	${RM} ${KDEDIR}/share/kde/apps/kapptemplate/admin/Makefile.in

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
