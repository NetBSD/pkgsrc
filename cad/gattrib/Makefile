# $NetBSD: Makefile,v 1.4 2005/01/11 03:16:23 dmcmahill Exp $

DISTNAME=		geda-gattrib-${PKGVERSION}
PKGNAME=		gattrib-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		wulf@NetBSD.org
HOMEPAGE=		http://www.brorson.com/gEDA/gattrib/
COMMENT=		Attribute editor for gEDA

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
