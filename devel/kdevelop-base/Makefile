# $NetBSD: Makefile,v 1.34 2004/10/03 00:13:29 tv Exp $

DISTNAME=	kdevelop-3.1.0
PKGNAME=	kdevelop-base-3.1.0
PKGREVISION=	1
CATEGORIES=	devel kde

HOMEPAGE=       http://www.kdevelop.org/
COMMENT=	Base modules for IDE for Unix/X11/KDE

.include "../../meta-pkgs/kde3/Makefile.kde3"

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK3=		yes

DEPENDS+=		automake>=1.7:../../devel/automake
DEPENDS+=		doxygen>=1.3.5:../../devel/doxygen
DEPENDS+=		graphviz>=1.10nb1:../../graphics/graphviz
DEPENDS+=		htdig>=3.1.6:../../www/htdig
DEPENDS+=		a2ps>=4.12:../../print/a2ps
DEPENDS+=		kdelibdocs>=3.2:../../x11/kdelibdocs3
DEPENDS+=		qt3-docs>=3.1.1:../../x11/qt3-docs
DEPENDS+=		qt3-tools>=3.1.1:../../x11/qt3-tools

CONFLICTS+=	kdevelop<=1.3

USE_PERL5=	run

REPLACE_PERL= \
	kdevprj2kdevelop \
	doc/tools/index-python \
	doc/tools/index-texi \
	doc/tools/toc-docbook \
	doc/tools/toc-gsdoc \
	doc/tools/toc-python \
	doc/tools/toc-texi \
	languages/perl/app_templates/perlhello/app.pl \
	languages/perl/file_templates/pl

EVAL_PREFIX+=	\
	QT3DIR=qt3 \
	KDELIBDIR=kdelibs

CONFIGURE_ARGS+= \
	--with-qtdoc-dir=${QT3DIR}/qt3/doc/html \
	--with-kdelibsdoxy-dir=${KDELIBDIR}/share/doc/kde/HTML/en/kdelibs-apidocs

BDB_ACCEPTED=	db3 db4
.include "../../mk/bdb.buildlink3.mk"
CPPFLAGS+= -I${BDBBASE}/include/${BDB_TYPE}

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../devel/kdesdk3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
