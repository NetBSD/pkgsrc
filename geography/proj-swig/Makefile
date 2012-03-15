# $NetBSD: Makefile,v 1.15 2012/03/15 11:53:28 obache Exp $
#

DISTNAME=		proj-swig-0.02
PKGREVISION=		4
CATEGORIES=		geography
MASTER_SITES=		http://acert.ir.bbn.com/downloads/acert-geospatial/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://acert.ir.bbn.com/downloads/acert-geospatial/
COMMENT=		Guile and python wrappers for proj

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# Defines PYSITELIB, apparently.
PY_PATCHPLIST=		yes

# The perl build is commented out upstream, so this doesn't have any
# effect.
SUBST_CLASSES+=		pkg
SUBST_STAGE.pkg=	pre-configure
SUBST_MESSAGE.pkg=	Replacing /usr/pkg with the correct PREFIX.
SUBST_FILES.pkg=	Makefile.in
SUBST_SED.pkg=		-e 's,/usr/pkg,${PREFIX},g'

.include "../../devel/swig/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
