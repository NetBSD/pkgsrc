# $NetBSD: Makefile,v 1.12 2006/09/01 12:00:42 dmcmahill Exp $

DISTNAME=		geda-gattrib-${PKGVERSION}
PKGNAME=		gattrib-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		wulf@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Attribute editor for gEDA

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
