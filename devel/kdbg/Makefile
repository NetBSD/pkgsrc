# $NetBSD: Makefile,v 1.6 1999/12/14 20:03:41 tron Exp $

DISTNAME=	kdbg-1.0.1
CATEGORIES=	devel kde
MASTER_SITES=	http://members.telecom.at/~johsixt/ \
		ftp://ftp.eudaptics.co.at/pub/people/jsixt/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=       http://members.telecom.at/~johsixt/kdbg.html

BUILD_DEPENDS+= ${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=	autoconf-2.13:../../devel/autoconf
DEPENDS+=	automake-1.4:../../devel/automake
DEPENDS+=	kdevel-1.1.*:../../x11/kdelibs
DEPENDS+=	png-1.*:../../graphics/png

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-dir=${PREFIX} \
		--with-qt-includes=${PREFIX}/include/qt \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include

CONFIGURE_ENV=	KDEDIR=${PREFIX}

.include "../../mk/bsd.pkg.mk"
