# $NetBSD: Makefile,v 1.7 1999/10/26 18:10:04 wennmach Exp $

DISTNAME=	kdevelop-1.0beta2
CATEGORIES=	devel kde
MASTER_SITES=	http://fara3.cs.uni-potsdam.de/~smeier/kdevelop_home/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=       http://www.kdevelop.org/

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	a2ps-*:../../print/a2ps
DEPENDS+=	autoconf-*:../../devel/autoconf
DEPENDS+=	automake-*:../../devel/automake
DEPENDS+=	gdbm-1.*:../../databases/gdbm
DEPENDS+=	gmake-*:../../devel/gmake
DEPENDS+=	glimpse-*:../../textproc/glimpse
DEPENDS+=	kdegraphics-1.*:../../graphics/kdegraphics
DEPENDS+=	kdbg-1.0beta2:../../devel/kdbg
DEPENDS+=	libungif-*:../../graphics/libungif

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
