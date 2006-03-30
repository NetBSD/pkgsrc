# $NetBSD: Makefile,v 1.10 2006/03/30 03:44:42 jlam Exp $

DISTNAME=	g-wrap-1.3.4
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnucash.org/pub/g-wrap/source/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnucash.org/
COMMENT=	Tool for importing types, functions, and constants into guile 1.4

DEPENDS+=	guile-slib>=2.4.2nb6:../../devel/guile-slib


GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake makeinfo
USE_LIBTOOL=		YES
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--with-modules-dir=${PREFIX}/share/guile
CONFIGURE_ENV+=		ac_cv_path_RSCHEME="nope"

.include "../../devel/glib/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../devel/guile-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
