# $NetBSD: Makefile,v 1.19 2003/05/02 11:54:33 wiz Exp $

DISTNAME=	kdevelop-2.1.5_for_KDE_3.1
PKGNAME=	kdevelop-base-2.1.5
PKGREVISION=	1
CATEGORIES=	devel kde

MASTER_SITES=	ftp://ftp.kde.org/pub/kde/stable/kdevelop-2.1.5/src/ \
		ftp://ftp.us.kde.org/pub/kde/stable/kdevelop-2.1.5/src/ \
		ftp://ftp.de.kde.org/pub/kde/stable/kdevelop-2.1.5/src/
HOMEPAGE=       http://www.kdevelop.org/
COMMENT=	Base modules for IDE for Unix/X11/KDE

.include "../../x11/kde3/Makefile.kde3"

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK2=		yes

DEPENDS+=		automake>=1.7:../../devel/automake
DEPENDS+=		kdoc>=3.0:../../textproc/kdoc
DEPENDS+=		htdig>=3.1.6:../../www/htdig
DEPENDS+=		a2ps>=4.12:../../print/a2ps
DEPENDS+=		kdelibdocs>=3.1:../../x11/kdelibdocs3
DEPENDS+=		qt3-tools>=3.1.1:../../x11/qt3-tools
DEPENDS+=		kdesdk>=3.1:../../devel/kdesdk3

CONFLICTS+=	kdevelop<=1.3

USE_PERL5=	yes

REPLACE_PERL= \
	kdevelop/tools/processesend.pl \
	kdevelop/tools/processes.pl.in

EVAL_PREFIX+=	\
	QT3DIR=qt3 \
	KDELIBDIR=kdelibs

CONFIGURE_ARGS+= \
	--with-qtdoc-dir=${QT3DIR}/qt3/doc/html \
	--with-kdelibsdoc-dir=${KDELIBDIR}/share/doc/kde/HTML/en/kdelibs \
	--enable-kdoc3

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
