# $NetBSD: Makefile,v 1.1.1.1 2000/06/26 16:57:07 rh Exp $
#

DISTNAME=	g-wrap-0.9.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnucash.org/pub/g-wrap/source/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.cs.cmu.edu/afs/cs.cmu.edu/usr/chrislee/www/Software/g-wrap/

DEPENDS+=	guile>=1.3.4:../../lang/guile

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
