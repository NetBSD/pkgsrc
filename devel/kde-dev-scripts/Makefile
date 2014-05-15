# $NetBSD: Makefile,v 1.7 2014/05/15 14:41:46 adam Exp $

DISTNAME=	kde-dev-scripts-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	devel
COMMENT=	Scripts useful during development of KDE software

.include "../../meta-pkgs/kde4/Makefile.kde4"

REPLACE_BASH+= \
	create_makefile \
	create_svnignore \
	draw_lib_dependencies \
	makeobj \
	package_crystalsvg \
	svnversions

REPLACE_PERL+= \
	colorcvs \
	colorsvn \
	cvs-clean \
	cvsblame \
	cvscheck \
	cvslastchange \
	cxxmetric \
	extend_dmalloc \
	extractattr \
	extractrc \
	fixheaders \
	fixkdeincludes \
	fixuifiles \
	generate_string_table.pl \
	includemocs \
	kde-spellcheck.pl \
	kdemangen.pl \
	krazy-licensecheck \
	noncvslist \
	png2mng.pl \
	rc2kcfgxt.pl \
	svn-clean \
	svnintegrate \
	svnlastchange

REPLACE_PYTHON+= \
	kde-systemsettings-tree.py \
	kde_generate_export_header \
	kdelnk2desktop.py \
	rename_source_files \
	zonetab2pot.py

REPLACE_SH+= \
	build-progress.sh \
	cvsaddcurrentdir

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

USE_TOOLS+=	gmake bash:run

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../lang/python/application.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
