# $NetBSD: Makefile,v 1.30 2004/12/03 15:55:36 wiz Exp $

DISTNAME=	g-wrap-1.3.4
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnucash.org/pub/g-wrap/source/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnucash.org/
COMMENT=	Tool for importing types, functions, and constants into guile

DEPENDS+=	guile-slib-2.4.2nb[0-5]:../../devel/guile14-slib

USE_BUILDLINK3=		YES

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
MAKE_ENV+=		GUILE14_SUBDIR=${GUILE14_SUBDIR:Q}

USE_MAKEINFO=		YES
INFO_FILES=		g-wrap.info

CONFIGURE_ARGS+=	--with-modules-dir=${PREFIX}/${GUILE14_SUBDIR}/share/guile
CONFIGURE_ENV+=		ac_cv_path_RSCHEME="nope"

.include "../../devel/glib/buildlink3.mk"
.include "../../lang/guile14/buildlink3.mk"
.include "../../devel/guile14-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
