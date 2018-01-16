# $NetBSD: Makefile,v 1.1 2018/01/16 13:33:32 wiz Exp $

DISTNAME=	guile-slib-3.2.5
PKGNAME=	${DISTNAME:S/guile/guile22/}
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB glue files for guile

DEPENDS+=	slib>=3.2.5nb1:../../devel/slib

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	share/guile share/guile/2.2 share/guile/site

do-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/guile/site/slib
	${LN} -sf ${PREFIX}/share/slib \
		${DESTDIR}${PREFIX}/share/guile/site/slib
	${RM} -f ${DESTDIR}${PREFIX}/share/guile/slibcat
	cd ${DESTDIR}${PREFIX}/share/guile/site/slib && \
		GUILE_LOAD_PATH=${PREFIX}/share \
		GUILE_IMPLEMENTATION_PATH=${DESTDIR}${PREFIX}/share/guile/2.2 \
		guile -q -c "(begin (use-modules (ice-9 slib)) (require 'new-catalog))"

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
