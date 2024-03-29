# $NetBSD: Makefile,v 1.58 2024/02/06 11:05:14 markd Exp $

DISTNAME=	kde-dev-scripts-${KAPPSVER}
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/
COMMENT=	Scripts useful during development of KDE software
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge bash:run perl:run

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
	grantlee_strings_extractor.py \
	kde-systemsettings-tree.py \
	kde_generate_export_header \
	kdelnk2desktop.py \
	rename_source_files \
	reviewboard-am \
	zonetab2pot.py

REPLACE_SH+= \
	build-progress.sh \
	cvsaddcurrentdir

.include "../../lang/python/application.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
