# $NetBSD: Makefile,v 1.26 2001/11/29 19:46:11 jlam Exp $

DISTNAME=	kdbg-1.2.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kdbg/} \
		ftp://ftp.eudaptics.com/pub/people/jsixt/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=       http://members.telecom.at/~johsixt/kdbg.html
COMMENT=	Graphical User Interface around gdb using KDE

BUILD_USES_MSGFMT=	yes
DEPENDS+=	automake>=1.4:../automake
DEPENDS+=	kdevelop-base-1.*:../kdevelop-base

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
