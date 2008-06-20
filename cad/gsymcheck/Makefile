# $NetBSD: Makefile,v 1.35 2008/06/20 01:09:08 joerg Exp $
#

DISTNAME=		geda-gsymcheck-${PKGVERSION}
PKGNAME=		gsymcheck-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		EDA (Electronic Design Automation) symbol checker

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		geda-symbols-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

.include "../../cad/libgeda/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
