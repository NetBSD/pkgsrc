# $NetBSD: Makefile,v 1.2 2000/08/15 02:18:46 jlam Exp $
#

DISTNAME=	g-wrap-0.9.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnucash.org/pub/g-wrap/source/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.cs.cmu.edu/afs/cs.cmu.edu/usr/chrislee/www/Software/g-wrap/

DEPENDS+=	guile>=1.3.4:../../lang/guile

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	ac_cv_path_RSCHEME="nope"

USE_LIBTOOL=	# defined
LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
