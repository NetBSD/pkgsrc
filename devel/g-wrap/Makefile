# $NetBSD: Makefile,v 1.14 2003/01/24 04:22:42 jlam Exp $

DISTNAME=	g-wrap-1.2.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=g-wrap/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://web.mit.edu/chlee/www/Software/g-wrap/index.html
COMMENT=	tool for importing types, functions, and constants into guile

DEPENDS+=	guile-slib>=2.4.2:../../devel/guile-slib

USE_BUILDLINK2=		YES
USE_GMAKE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-modules-dir=${GUILE14_PREFIX}/share/guile
CONFIGURE_ENV+=		GUILE=${GUILE14}
CONFIGURE_ENV+=		BUILD_GUILE=${GUILE14_CONFIG}
CONFIGURE_ENV+=		ac_cv_path_RSCHEME="nope"

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../lang/guile14/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
