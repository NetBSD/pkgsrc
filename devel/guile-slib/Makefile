# $NetBSD: Makefile,v 1.50 2022/03/09 20:35:39 gdt Exp $

SLIBVERSION=	3.2.6
DISTNAME=	guile-slib-${SLIBVERSION}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://people.csail.mit.edu/jaffer/SLIB
COMMENT=	SLIB glue files for guile

# This package is currently linked to guile22.

DEPENDS+=	slib>=${SLIBVERSION}:../../devel/slib

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	guile/2.2/share/guile guile/2.2/share/guile/site

do-install:
	${RM} -f ${DESTDIR}${PREFIX}/guile/2.2/share/guile/site/slib
	${LN} -sf ${PREFIX}/share/slib \
		${DESTDIR}${PREFIX}/guile/2.2/share/guile/site/slib
	${RM} -f ${DESTDIR}${PREFIX}/guile/2.2/share/guile/slibcat
	cd ${DESTDIR}${PREFIX}/guile/2.2/share/guile/site/slib && \
		GUILE_LOAD_PATH=${PREFIX}/share \
		GUILE_IMPLEMENTATION_PATH=${DESTDIR}${PREFIX}/guile/2.2/share/guile \
		guile -q -c "(begin (use-modules (ice-9 slib)) (require 'new-catalog))"

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
