# $NetBSD: Makefile,v 1.137 2016/03/05 11:28:22 jperkin Exp $

DISTNAME=	kdevelop_3.5.5.orig
PKGNAME=	kdevelop-base-3.5.5
PKGREVISION=	51
CATEGORIES=	devel kde
MASTER_SITES=	http://download.opensuse.org/repositories/home:/amilcarlucas/xUbuntu_6.06/

HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	Base modules for IDE for Unix/X11/KDE
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

WRKSRC=		${WRKDIR}/kdevelop-3.5.5

.include "../../meta-pkgs/kde3/Makefile.kde3"
# default in Makefile.kde3 is wrong, so we need to set EXTRACT_SUFX here
EXTRACT_SUFX=	.tar.gz

DEPENDS+=		automake>=1.7:../../devel/automake
DEPENDS+=		doxygen>=1.3.5:../../devel/doxygen
DEPENDS+=		graphviz>=1.10nb1:../../graphics/graphviz
DEPENDS+=		htdig>=3.2.0:../../www/htdig
DEPENDS+=		a2ps>=4.12:../../print/a2ps
DEPENDS+=		kdelibdocs>=3.2:../../x11/kdelibdocs3
DEPENDS+=		qt3-docs>=3.1.1:../../x11/qt3-docs
DEPENDS+=		qt3-tools>=3.1.1:../../x11/qt3-tools

CONFLICTS+=	kdevelop<=1.3

BDB_ACCEPTED=		db4 db5
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt perl:run
MAKE_JOBS_SAFE=		no

REPLACE_PERL+=		kdevprj2kdevelop
REPLACE_PERL+=		doc/tools/index-python
REPLACE_PERL+=		doc/tools/index-texi
REPLACE_PERL+=		doc/tools/toc-docbook
REPLACE_PERL+=		doc/tools/toc-gsdoc
REPLACE_PERL+=		doc/tools/toc-python
REPLACE_PERL+=		doc/tools/toc-texi
REPLACE_PERL+=		languages/perl/app_templates/perlhello/app.pl
REPLACE_PERL+=		languages/perl/file_templates/pl

SUBST_CLASSES+=		perlpath
SUBST_STAGE.perlpath=	post-patch
SUBST_MESSAGE.perlpath=	Fix perl path.
SUBST_FILES.perlpath=	languages/perl/perlparser.cpp parts/doxygen/config.cpp
SUBST_SED.perlpath=	-e s:/usr/bin/perl:${PERL5:Q}:

CONFIGURE_ARGS+=	--with-db-includedir=${BDBBASE}/include/${BDB_TYPE}
CONFIGURE_ARGS+=	--with-db-libdir=${BDBBASE}/lib
CONFIGURE_ARGS+=	--with-db-lib=${BDB_TYPE}
CONFIGURE_ARGS+=	--with-qtdoc-dir=${LOCALBASE}/qt3/doc/html
CONFIGURE_ARGS+=	--with-kdelibsdoxy-dir=${LOCALBASE}/share/doc/kde/HTML/en/kdelibs-apidocs

.include "options.mk"

.include "../../meta-pkgs/kde3/kde3.mk"

# XXX: need to include compiler.mk before including bdb.buildlink3.mk,
# otherwise f2c is not added as a dependency correctly
.include "../../mk/compiler.mk"
.include "../../devel/kdesdk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
