# $NetBSD: Makefile,v 1.113 2014/01/01 11:52:05 wiz Exp $

DISTNAME=	kdesdk-${_KDE_VERSION}
PKGREVISION=	47
CATEGORIES=	devel
COMMENT=	Support applications and tools used by KDE developers

CONFLICTS+=	cervisia-[0-9]*
CONFLICTS+=	umbrello-[0-9]*

BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../meta-pkgs/kde3/Makefile.kde3"

BDB_ACCEPTED=		db4 db5
USE_TOOLS+=		perl:run bash:run pod2man
CONFIGURE_ARGS+=	--with-db-dir=${BDBBASE}
CONFIGURE_ARGS+=	--with-db-include=${BDB_TYPE}/db.h
#CONFIGURE_ARGS+=	--with-db-include-dir=${BDBBASE}/include/${BDB_TYPE}
CONFIGURE_ARGS+=	--with-db-name=${BDB_TYPE}

REPLACE_PERL+=	cervisia/change_colors.pl \
		cervisia/move_repositories.pl \
		cervisia/cervisia-change_repos_list.pl \
		cervisia/cervisia-normalize_cvsroot.pl \
		kapptemplate/admin/am_edit \
		kapptemplate/admin/bcheck.pl \
		kapptemplate/admin/debianrules \
		kapptemplate/admin/nmcheck \
		kapptemplate/admin/conf.change.pl \
		kapptemplate/admin/config.pl \
		kapptemplate/admin/detect-autoconf.pl \
		kcachegrind/converters/dprof2calltree \
		kcachegrind/converters/memprof2calltree \
		kcachegrind/converters/op2calltree \
		scripts/authors2xml.pl \
		scripts/check_licenses \
		scripts/colorcvs \
		scripts/colorsvn \
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
		scripts/kdesvn-build \
		scripts/licensecheck \
		scripts/noncvslist \
		scripts/png2mng.pl \
		scripts/rc2kcfgxt.pl \
		scripts/svn-clean \
		scripts/svnlastchange \
		kunittest/kunittest_debughelper

REPLACE_BASH+=	scripts/cvs2dist \
		scripts/create_makefile \
		scripts/kde-build \
		scripts/makeobj \
		scripts/package_crystalsvg \
		scripts/svn2dist \
		scripts/svnversions \
		kunittest/kunittest \
		kunittest/kunittestmod \
		kapptemplate/kapptemplate.common

SUBST_CLASSES+=		make
SUBST_STAGE.make=	post-patch
SUBST_FILES.make=	kapptemplate/Makefile.in
SUBST_SED.make=		-e 's,/usr/bin/env bash,${BASH},'

REPLACE_PYTHON+= \
		kcachegrind/converters/hotshot2calltree \
		scripts/kdelnk2desktop.py \
		scripts/zonetab2pot.py

# REPLACE_PHP+= kcachegrind/converters/pprof2calltree
SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	kcachegrind/converters/pprof2calltree
SUBST_SED.php=		-e 's,/usr/bin/env php,${PREFIX}/bin/php,'

CHECK_INTERPRETER_SKIP+=	share/kde/apps/umbrello/headings/*

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	# empty
.if ${OPSYS} == "Linux"
PLIST_SRC+=	${PKGDIR}/PLIST.kmtrace
.endif
PLIST_SRC+=	${PKGDIR}/PLIST

.if ${OPSYS} == "DragonFly"
CONFIGURE_ENV+= LEX="${PREFIX}/bin/flex"
.include "../../devel/flex/buildlink3.mk"
.else
USE_TOOLS+= lex
.endif

.include "options.mk"

# Makefile{,.am,.in} weren't supposed to be installed so clean up
post-install:
	${RM} ${DESTDIR}${KDEDIR}/share/kde/apps/kapptemplate/admin/Makefile
	${RM} ${DESTDIR}${KDEDIR}/share/kde/apps/kapptemplate/admin/Makefile.am
	${RM} ${DESTDIR}${KDEDIR}/share/kde/apps/kapptemplate/admin/Makefile.in

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
