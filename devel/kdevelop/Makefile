# $NetBSD: Makefile,v 1.1.1.1 1999/09/23 10:54:52 wennmach Exp $

DISTNAME=	kdevelop-1.0beta2
CATEGORIES=	devel kde
MASTER_SITES=	http://fara3.cs.uni-potsdam.de/~smeier/kdevelop_home/

MAINTAINER=	nick@nthcliff.demon.co.uk
HOMEPAGE=       http://www.kdevelop.org/

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	autoconf-*:../../devel/autoconf
DEPENDS+=	automake-*:../../devel/automake
DEPENDS+=	gdbm-1.*:../../databases/gdbm
DEPENDS+=	kdelibs-1.*:../../x11/kdelibs
DEPENDS+=	perl-5.*:../../lang/perl5
DEPENDS+=       qt-1.*:../../x11/qt
RUN_DEPENDS+=	gmake:../../devel/gmake
RUN_DEPENDS+=	a2ps:../../print/a2ps
RUN_DEPENDS+=	glimpse:../../textproc/glimpse
RUN_DEPENDS+=	kpaint:../../graphics/kdegraphics
RUN_DEPENDS+=	kiconedit:../../graphics/kdegraphics

USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-dir=${PREFIX} \
		--with-qt-includes=${PREFIX}/include/qt
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${PREFIX}

.include "../../mk/bsd.pkg.mk"
