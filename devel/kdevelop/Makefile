# $NetBSD: Makefile,v 1.21 2000/12/19 14:17:27 wulf Exp $

DISTNAME=	kdevelop-1.3
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=       http://www.kdevelop.org/

BUILD_DEPENDS+= ${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=       autoconf-*:../../devel/autoconf
DEPENDS+=       automake-*:../../devel/automake
DEPENDS+=       a2ps-*:../../print/a2ps
DEPENDS+=       kdebase-1.*:../../x11/kdebase
DEPENDS+=       kdoc-2*:../../textproc/kdoc

USE_PERL5=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX+=	QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-qt-dir=${QT1DIR}/qt1
CONFIGURE_ENV=	"KDEDIR=${KDEBASEDIR} QTDIR=${QT1DIR}/qt1"

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${QT1DIR}/qt1/lib

.include "../../mk/bsd.pkg.mk"
