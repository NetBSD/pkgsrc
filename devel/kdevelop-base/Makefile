# $NetBSD: Makefile,v 1.10 2001/12/04 20:45:31 skrll Exp $

DISTNAME=	kdevelop-2.0.2
PKGNAME=	${DISTNAME:S/-/-base-/}
CATEGORIES=	devel kde
COMMENT=	Base modules for IDE for Unix/X11/KDE

.include "../../x11/kde2/Makefile.kde2"

HOMEPAGE=       http://www.kdevelop.org/

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK_ONLY=	yes
DEPENDS+=		automake>=1.4:../../devel/automake
DEPENDS+=		kdoc-2.2.2:../../textproc/kdoc
DEPENDS+=		htdig>=3.1.5:../../www/htdig
DEPENDS+=		a2ps>=4.12:../../print/a2ps
DEPENDS+=		kdelibdocs>=2.2.2:../../x11/kdelibdocs2
DEPENDS+=		qt2-designer-kde>=2.3.1:../../x11/qt2-designer-kde
DEPENDS+=		kdesdk>=2.2.2:../../devel/kdesdk2

CONFLICTS+=	kdevelop<=1.3

USE_PERL5=	yes

REPLACE_PERL= \
	${WRKSRC}/kdevelop/tools/processesend.pl \
	${WRKSRC}/kdevelop/tools/processes.pl.in

EVAL_PREFIX+=	\
	QT2DIR=qt2 \
	KDELIBDIR=kdelibs

CONFIGURE_ARGS+= \
	--with-qtdoc-dir=${QT2DIR}/qt2/doc/html \
	--with-kdelibsdoc-dir=${KDELIBDIR}/share/doc/kde/HTML/en/kdelibs \
	--enable-kdoc2

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
