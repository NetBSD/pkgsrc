# $NetBSD: Makefile,v 1.25 2001/03/01 13:35:33 wiz Exp $

DISTNAME=	kdevelop-1.3
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/
DISTFILES=	kdevelop-1.3.tar.bz2 \
		c_cpp_reference-1.0.tar.gz

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=       http://www.kdevelop.org/
COMMENT=	Integrated Development Enviroment for Unix/X11/KDE

BUILD_DEPENDS+= msgfmt:../../devel/gettext
DEPENDS+=       autoconf-*:../../devel/autoconf
DEPENDS+=       automake-*:../../devel/automake
DEPENDS+=       a2ps-*:../../print/a2ps
DEPENDS+=       kdebase-1.*:../../x11/kdebase
DEPENDS+=       kdbg>=1.0:../../devel/kdbg
DEPENDS+=       kdoc-2*:../../textproc/kdoc
DEPENDS+=       htdig>=3.1.5:../../www/htdig
DEPENDS+=       a2ps>=4.12:../../print/a2ps
DEPENDS+=	kdelibdocs-1*:../../x11/kdelibdocs

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

post-install:
		cd ${WRKDIR}/c_cpp_reference-1.0  && \
		./configure --with-qt-dir=${QT1DIR}/qt1 \
		&& ${GMAKE} && ${GMAKE} install

.include "../../mk/bsd.pkg.mk"
