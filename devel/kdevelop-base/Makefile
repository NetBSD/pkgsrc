# $NetBSD: Makefile,v 1.9 2001/11/29 19:46:11 jlam Exp $

DISTNAME=	kdevelop-1.3
PKGNAME=	${DISTNAME:S/-/-base-/}
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=       http://www.kdevelop.org/
COMMENT=	Base modules for IDE for Unix/X11/KDE

BUILD_USES_MSGFMT=	yes
DEPENDS+=       automake>=1.4:../../devel/automake
DEPENDS+=       kdebase-1.*:../../x11/kdebase
DEPENDS+=       kdoc-2*:../../textproc/kdoc
DEPENDS+=       htdig>=3.1.5:../../www/htdig
DEPENDS+=       a2ps>=4.12:../../print/a2ps
DEPENDS+=	kdelibdocs-1*:../../x11/kdelibdocs

CONFLICTS+=	kdevelop<=1.3

USE_PERL5=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX+=	QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-qt-dir=${QT1DIR}/qt1 \
		--with-qtdoc-dir=${QT1DIR}/qt1/share/doc/qt/html \
		--with-kdelibsdoc-dir=${KDEBASEDIR}/share/doc/kde/HTML/default/kdelibs \
		--enable-kdoc2
CONFIGURE_ENV=	"KDEDIR=${KDEBASEDIR} QTDIR=${QT1DIR}/qt1"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${QT1DIR}/qt1/lib

.include "../../mk/bsd.pkg.mk"
