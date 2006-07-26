# $NetBSD: Makefile,v 1.1.1.1 2006/07/26 22:46:31 gdt Exp $
#

DISTNAME=		proj-swig-0.01
CATEGORIES=		geography
MASTER_SITES=		http://acert.ir.bbn.com/downloads/acert-geospatial/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://acert.ir.bbn.com/downloads/acert-geospatial/
COMMENT=		guile and python wrappers for proj

USE_LANGUAGES+=		c

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes
GNU_CONFIGURE=		yes

PY_PATCHPLIST=

.include "../../lang/python/extension.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
