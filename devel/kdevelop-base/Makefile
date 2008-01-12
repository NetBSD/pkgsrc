# $NetBSD: Makefile,v 1.69 2008/01/12 11:36:31 adam Exp $

DISTNAME=	kdevelop-3.5.0
PKGNAME=	kdevelop-base-3.5.0
PKGREVISION=	3
CATEGORIES=	devel kde

HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	Base modules for IDE for Unix/X11/KDE

.include "../../meta-pkgs/kde3/Makefile.kde3"

DEPENDS+=		automake>=1.7:../../devel/automake
DEPENDS+=		doxygen>=1.3.5:../../devel/doxygen
DEPENDS+=		graphviz>=1.10nb1:../../graphics/graphviz
DEPENDS+=		htdig>=3.2.0:../../www/htdig-devel
DEPENDS+=		a2ps>=4.12:../../print/a2ps
DEPENDS+=		kdelibdocs>=3.2:../../x11/kdelibdocs3
DEPENDS+=		qt3-docs>=3.1.1:../../x11/qt3-docs
DEPENDS+=		qt3-tools>=3.1.1:../../x11/qt3-tools

CONFLICTS+=	kdevelop<=1.3

USE_TOOLS+=	msgfmt perl:run
USE_LANGUAGES+=	fortran

REPLACE_PERL+= \
	kdevprj2kdevelop \
	doc/tools/index-python \
	doc/tools/index-texi \
	doc/tools/toc-docbook \
	doc/tools/toc-gsdoc \
	doc/tools/toc-python \
	doc/tools/toc-texi \
	languages/perl/app_templates/perlhello/app.pl \
	languages/perl/file_templates/pl

SUBST_CLASSES+=		perlpath
SUBST_STAGE.perlpath=	post-patch
SUBST_MESSAGE.perlpath=	Fix perl path.
SUBST_FILES.perlpath=	languages/perl/perlparser.cpp parts/doxygen/config.cpp
SUBST_SED.perlpath=	-e s:/usr/bin/perl:${PERL5}:

EVAL_PREFIX+=	\
	QT3DIR=qt3 \
	KDELIBDIR=kdelibs

CONFIGURE_ARGS+= \
	--with-db-includedir=${BUILDLINK_PREFIX.db4}/include/db4 \
	--with-db-libdir=${BUILDLINK_PREFIX.db4}/lib \
	--with-db-lib=db4 \
	--with-qtdoc-dir=${QT3DIR}/qt3/doc/html \
	--with-kdelibsdoxy-dir=${KDELIBDIR}/share/doc/kde/HTML/en/kdelibs-apidocs

.include "options.mk"

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/kdesdk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
