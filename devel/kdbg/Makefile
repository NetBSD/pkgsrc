# $NetBSD: Makefile,v 1.17 2001/02/16 14:38:32 wiz Exp $

DISTNAME=	kdbg-1.0.1
CATEGORIES=	devel kde
MASTER_SITES=	http://members.telecom.at/~johsixt/ \
		ftp://ftp.eudaptics.co.at/pub/people/jsixt/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=       http://members.telecom.at/~johsixt/kdbg.html
COMMENT=	Graphical User Interface around gdb using KDE

BUILD_DEPENDS+= msgfmt:../../devel/gettext
DEPENDS+=	autoconf-2.13:../autoconf
DEPENDS+=	automake-1.4:../automake
DEPENDS+=	kdevelop-1.*:../kdevelop
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

EVAL_PREFIX+=	QT1DIR=qt1
CONFIGURE_ARGS=	--with-qt-dir=${QT1DIR}/qt1 \
		--with-qt-includes=${QT1DIR}/qt1/include \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include

CONFIGURE_ENV=	KDEDIR=${PREFIX}

.include "../../mk/bsd.pkg.mk"
