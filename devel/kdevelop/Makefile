# $NetBSD: Makefile,v 1.10 1999/12/14 20:03:42 tron Exp $

DISTNAME=	kdevelop-1.0
CATEGORIES=	devel kde
MASTER_SITES=	ftp://ftp.e-technik.fh-muenchen.de/pub/unix/ide/KDevelop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=       http://www.kdevelop.org/

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	a2ps-*:../../print/a2ps
DEPENDS+=	gdbm-1.*:../../databases/gdbm
DEPENDS+=	glimpse-*:../../textproc/glimpse
DEPENDS+=	kdegraphics-1.*:../../graphics/kdegraphics
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
