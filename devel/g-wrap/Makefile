# $NetBSD: Makefile,v 1.22 2003/08/09 10:44:40 seb Exp $

DISTNAME=	g-wrap-1.3.4
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnucash.org/pub/g-wrap/source/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://web.mit.edu/chlee/www/Software/g-wrap/index.html
COMMENT=	Tool for importing types, functions, and constants into guile

DEPENDS+=	guile-slib>=2.4.2:../../devel/guile-slib

USE_BUILDLINK2=		YES

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

USE_MAKEINFO=		YES
INFO_FILES=		g-wrap.info

CONFIGURE_ARGS+=	--with-modules-dir=${GUILE14_PREFIX}/share/guile
CONFIGURE_ENV+=		GUILE=${GUILE14}
CONFIGURE_ENV+=		BUILD_GUILE=${GUILE14_CONFIG}
CONFIGURE_ENV+=		ac_cv_path_RSCHEME="nope"
CONFIGURE_ENV+=		ac_cv_path_GUILE="${LOCALBASE}/guile/1.4/bin/guile"

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/glib/buildlink2.mk"
.include "../../lang/guile14/buildlink2.mk"
.include "../../devel/guile-gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
