# $NetBSD: Makefile,v 1.69 2026/01/07 08:46:32 wiz Exp $

DISTNAME=	kde-dev-scripts-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/
COMMENT=	Scripts useful during development of KDE software
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge bash:run perl:run

REPLACE_BASH+= \
	addmocincludes \
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
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
