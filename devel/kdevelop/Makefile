# $NetBSD: Makefile,v 1.12 2000/05/05 13:54:10 wulf Exp $

DISTNAME=	kdevelop-1.2
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
CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-qt-dir=${X11BASE}/qt1

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	"KDEDIR=${PREFIX} QTDIR=${X11BASE}/qt1"

.include "../../mk/bsd.pkg.mk"
