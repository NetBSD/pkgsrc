# $NetBSD: Makefile,v 1.12 2002/07/17 11:28:04 skrll Exp $

DISTNAME=	kdevelop-2.1.2_for_KDE_3.0
PKGNAME=	kdevelop-base-2.1.2
CATEGORIES=	devel kde

HOMEPAGE=       http://www.kdevelop.org/
COMMENT=	Base modules for IDE for Unix/X11/KDE

.include "../../x11/kde3/Makefile.kde3"

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK_ONLY=	yes

DEPENDS+=		automake>=1.4:../../devel/automake
DEPENDS+=		kdoc>=3.0:../../textproc/kdoc
DEPENDS+=		htdig>=3.1.6:../../www/htdig
DEPENDS+=		a2ps>=4.12:../../print/a2ps
DEPENDS+=		kdelibdocs>=3.0.1:../../x11/kdelibdocs3
DEPENDS+=		qt3-tools>=3.0.4:../../x11/qt3-tools
DEPENDS+=		kdesdk>=3.0.1:../../devel/kdesdk3

CONFLICTS+=	kdevelop<=1.3

USE_PERL5=	yes

REPLACE_PERL= \
	${WRKSRC}/kdevelop/tools/processesend.pl \
	${WRKSRC}/kdevelop/tools/processes.pl.in

EVAL_PREFIX+=	\
	QT3DIR=qt3 \
	KDELIBDIR=kdelibs

CONFIGURE_ARGS+= \
	--with-qtdoc-dir=${QT3DIR}/qt3/doc/html \
	--with-kdelibsdoc-dir=${KDELIBDIR}/share/doc/kde/HTML/en/kdelibs \
	--enable-kdoc3

.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
