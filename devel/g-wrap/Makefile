# $NetBSD: Makefile,v 1.11 2002/09/24 09:53:18 jlam Exp $

DISTNAME=	g-wrap-1.2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnucash.org/pub/g-wrap/source/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://web.mit.edu/chlee/www/Software/g-wrap/index.html
COMMENT=	tool for importing types, functions, and constants into guile

DEPENDS+=	guile-slib>=2.4.2:../../devel/guile-slib

USE_BUILDLINK2=		YES
USE_GMAKE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		ac_cv_path_RSCHEME="nope"

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../lang/guile/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
