# $NetBSD: Makefile,v 1.6 2022/03/05 18:35:58 gdt Exp $

SLIBVERSION=	3.2.6
DISTNAME=	guile-slib-${SLIBVERSION}
PKGNAME=	${DISTNAME:S/guile/guile22/}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://people.csail.mit.edu/jaffer/SLIB
COMMENT=	SLIB glue files for guile

DEPENDS+=	slib>=${SLIBVERSION}:../../devel/slib

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/guile share/guile/site

do-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/guile/site/slib
	${LN} -sf ${PREFIX}/share/slib \
		${DESTDIR}${PREFIX}/share/guile/site/slib
	${RM} -f ${DESTDIR}${PREFIX}/share/guile/slibcat
	cd ${DESTDIR}${PREFIX}/share/guile/site/slib && \
		GUILE_LOAD_PATH=${PREFIX}/share \
		GUILE_IMPLEMENTATION_PATH=${DESTDIR}${PREFIX}/share/guile \
		guile -q -c "(begin (use-modules (ice-9 slib)) (require 'new-catalog))"

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
