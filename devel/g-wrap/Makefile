# $NetBSD: Makefile,v 1.16 2003/05/02 11:54:24 wiz Exp $

DISTNAME=	g-wrap-1.3.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnucash.org/pub/g-wrap/source/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://web.mit.edu/chlee/www/Software/g-wrap/index.html
COMMENT=	tool for importing types, functions, and constants into guile

DEPENDS+=	guile-slib>=2.4.2:../../devel/guile-slib

USE_BUILDLINK2=		YES

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--with-modules-dir=${GUILE14_PREFIX}/share/guile
CONFIGURE_ENV+=		GUILE=${GUILE14}
CONFIGURE_ENV+=		BUILD_GUILE=${GUILE14_CONFIG}
CONFIGURE_ENV+=		ac_cv_path_RSCHEME="nope"

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/glib/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../devel/guile-gtk/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
