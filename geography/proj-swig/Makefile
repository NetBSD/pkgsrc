# $NetBSD: Makefile,v 1.4 2006/09/06 10:16:25 rillig Exp $
#

DISTNAME=		proj-swig-0.01
PKGREVISION=		2
CATEGORIES=		geography
MASTER_SITES=		http://acert.ir.bbn.com/downloads/acert-geospatial/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://acert.ir.bbn.com/downloads/acert-geospatial/
COMMENT=		Guile and python wrappers for proj

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}

PY_PATCHPLIST=          yes

SUBST_CLASSES+=		pkg
SUBST_STAGE.pkg=	pre-configure
SUBST_MESSAGE.pkg=	Replacing /usr/pkg with the correct PREFIX.
SUBST_FILES.pkg=	Makefile.in
SUBST_SED.pkg=		-e 's,/usr/pkg,${PREFIX},g'

.include "../../devel/swig/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
