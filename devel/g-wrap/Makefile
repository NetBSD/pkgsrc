# $NetBSD: Makefile,v 1.7 2001/10/03 09:10:23 jlam Exp $

DISTNAME=	g-wrap-1.1.10
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnucash.org/pub/g-wrap/source/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://web.mit.edu/chlee/www/Software/g-wrap/index.html
COMMENT=	tool for importing types, functions, and constants into guile

DEPENDS+=	guile-slib>=2.4.2:../../devel/guile-slib

GNU_CONFIGURE=	YES
USE_GMAKE=	YeS
USE_LIBTOOL=	YES

CONFIGURE_ENV+=		ac_cv_path_RSCHEME="nope"
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
