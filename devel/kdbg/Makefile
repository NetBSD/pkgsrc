# $NetBSD: Makefile,v 1.9 2000/03/30 15:22:43 tron Exp $

DISTNAME=	kdbg-1.0.1
CATEGORIES=	devel kde
MASTER_SITES=	http://members.telecom.at/~johsixt/ \
		ftp://ftp.eudaptics.co.at/pub/people/jsixt/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=       http://members.telecom.at/~johsixt/kdbg.html

BUILD_DEPENDS+= ${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=	autoconf-2.13:../autoconf
DEPENDS+=	automake-1.4:../automake
DEPENDS+=	kdevelop-1.*:../kdevelop
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-dir=${PREFIX}/qt1 \
		--with-qt-includes=${PREFIX}/qt1/include \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include

CONFIGURE_ENV=	KDEDIR=${PREFIX}

.include "../../mk/bsd.pkg.mk"
