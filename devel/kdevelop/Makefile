# $NetBSD: Makefile,v 1.11 2000/03/28 00:12:30 dmcmahill Exp $

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
CONFIGURE_ARGS=	--with-qt-dir=${X11BASE}/qt1 
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	"KDEDIR=${PREFIX} QTDIR=${X11BASE}/qt1"

.include "../../mk/bsd.pkg.mk"
