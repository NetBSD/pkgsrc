# $NetBSD: Makefile,v 1.5 2001/07/01 15:12:44 tron Exp $

DISTNAME=	g-wrap-1.1.10
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnucash.org/pub/g-wrap/source/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://web.mit.edu/chlee/www/Software/g-wrap/index.html
COMMENT=	tool for importing types, functions, and constants into guile

DEPENDS+=	guile>=1.3.4:../../lang/guile

GNU_CONFIGURE=	YES
USE_GMAKE=	YeS
USE_LIBTOOL=	YES

CONFIGURE_ENV+=		ac_cv_path_RSCHEME="nope"
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
