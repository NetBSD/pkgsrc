# $NetBSD: Makefile,v 1.5 1999/09/24 14:33:39 tron Exp $

DISTNAME=	kdevelop-1.0beta2
CATEGORIES=	devel kde
MASTER_SITES=	http://fara3.cs.uni-potsdam.de/~smeier/kdevelop_home/

MAINTAINER=	nick@nthcliff.demon.co.uk
HOMEPAGE=       http://www.kdevelop.org/

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	a2ps-*:../../print/a2ps
DEPENDS+=	autoconf-*:../../devel/autoconf
DEPENDS+=	automake-*:../../devel/automake
DEPENDS+=	gdbm-1.*:../../databases/gdbm
DEPENDS+=	gmake-*:../../devel/gmake
DEPENDS+=	glimpse-*:../../textproc/glimpse
DEPENDS+=	kdegraphics-1.*:../../graphics/kdegraphics

USE_PERL5=	yes
USE_X11BASE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-dir=${PREFIX} \
		--with-qt-includes=${PREFIX}/include/qt
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	KDEDIR=${PREFIX}

.include "../../mk/bsd.pkg.mk"
