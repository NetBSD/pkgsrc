# $NetBSD: Makefile,v 1.44 2012/10/31 11:17:05 asau Exp $

DISTNAME=	guile-slib-3.2.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB glue files for guile 1.8

DEPENDS+=	slib>=3.2.2:../../devel/slib

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/guile share/guile/1.8 share/guile/site

do-install:
	${LN} -sf ${PREFIX}/share/slib \
		${DESTDIR}${PREFIX}/share/guile/site/slib
	${RM} -f ${DESTDIR}${PREFIX}/share/guile/slibcat
	cd ${DESTDIR}${PREFIX}/share/guile/site/slib && \
		GUILE_LOAD_PATH=${PREFIX}/share \
		GUILE_IMPLEMENTATION_PATH=${DESTDIR}${PREFIX}/share/guile/1.8 \
		guile -q -c "(begin (use-modules (ice-9 slib)) (require 'new-catalog))"

# Our 1.8.2 package applies a necessary patch.
BUILDLINK_API_DEPENDS.guile+=	guile>=1.8.2
.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
