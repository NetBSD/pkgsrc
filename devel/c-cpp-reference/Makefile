# $NetBSD: Makefile,v 1.1.1.1 2001/03/04 17:52:46 tron Exp $

DISTNAME=	c_cpp_reference-1.0
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.kdevelop.org/
COMMENT=	C and C++ reference for the KDE IDE

DEPENDS+=	kdevelop-base>=1.3:../kdevelop-base

USE_PERL5=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

EVAL_PREFIX+=	QT1DIR=qt1 KDEBASEDIR=kdebase
CONFIGURE_ARGS=	--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-qt-dir=${QT1DIR}/qt1 \
		--with-qtdoc-dir=${QT1DIR}/qt1/share/doc/qt/html
CONFIGURE_ENV=	"KDEDIR=${KDEBASEDIR} QTDIR=${QT1DIR}/qt1"

.include "../../mk/bsd.pkg.mk"
