# $NetBSD: Makefile,v 1.8 2006/01/24 07:31:56 wiz Exp $

DISTNAME=		geda-gattrib-${PKGVERSION}
PKGNAME=		gattrib-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad

MAINTAINER=		wulf@NetBSD.org
HOMEPAGE=		http://www.brorson.com/gEDA/gattrib/
COMMENT=		Attribute editor for gEDA

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
