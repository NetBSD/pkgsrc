# $NetBSD: Makefile,v 1.3 2004/10/15 14:50:05 tv Exp $

DISTNAME=		geda-gattrib-${PKGVERSION}
PKGNAME=		gattrib-${PKGVERSION}
PKGREVISION=		2
CATEGORIES=		cad
MASTER_SITES=		http://www.brorson.com/gEDA/gattrib/

MAINTAINER=		wulf@NetBSD.org
HOMEPAGE=		http://www.brorson.com/gEDA/gattrib/
COMMENT=		Attribute editor for gEDA

.include "../../cad/geda/Makefile.common"

# override version number until synchronized with geda meta package
PKGVERSION=		20040313

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

.include "../../x11/gtk/buildlink3.mk"
.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
