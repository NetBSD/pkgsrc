# $NetBSD: Makefile,v 1.6 1999/11/07 17:25:30 hubertf Exp $
#

DISTNAME=       gnucash-1.1.25
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.gnucash.org/pub/gnucash/sources/

MAINTAINER=	mellon@isc.org
HOMEPAGE=	http://www.gnucash.org/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	swig-1.1p5:../../devel/swig
DEPENDS+=	eperl-2.2.14:../../textproc/eperl
DEPENDS+=	XmHTML-1.1.5:../../x11/XmHTML
DEPENDS+=	guile-1.3.2:../../lang/guile
DEPENDS+=	libperl-5.00404:../../lang/libperl

USE_X11=	yes
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-guile=${PREFIX} --with-perl-includes=${PREFIX}/lib/perl5/${MACHINE_ARCH}-netbsd/5.00404/CORE
USE_GMAKE=	yes

.include "../../mk/bsd.pkg.mk"
