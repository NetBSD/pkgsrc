# $NetBSD: Makefile,v 1.28 2017/09/09 23:52:28 dholland Exp $

DISTNAME=		proj-swig-0.02
PKGREVISION=		8
CATEGORIES=		geography
MASTER_SITES=		# http://acert.ir.bbn.com/downloads/acert-geospatial/

MAINTAINER=		gdt@NetBSD.org
#HOMEPAGE=		http://acert.ir.bbn.com/downloads/acert-geospatial/
COMMENT=		Guile and python wrappers for proj

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# Defines PYSITELIB, apparently.
PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.02

# Find guile20's includes
CFLAGS+=		-I${BUILDLINK_PREFIX.guile20}/include/guile/2.0

# Use swig2
SUBST_CLASSES+=		swig2
SUBST_STAGE.swig2=	pre-configure
SUBST_MESSSAGE.swig2=	Using swig2.
SUBST_FILES.swig2=	Makefile.in
SUBST_SED.swig2=	-e s/swig/swig2.0/

# The perl build is commented out upstream, so this doesn't have any
# effect.
SUBST_CLASSES+=		pkg
SUBST_STAGE.pkg=	pre-configure
SUBST_MESSAGE.pkg=	Replacing /usr/pkg with the correct PREFIX.
SUBST_FILES.pkg=	Makefile.in
SUBST_SED.pkg=		-e 's,/usr/pkg,${PREFIX},g'

.include "../../devel/swig2/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
