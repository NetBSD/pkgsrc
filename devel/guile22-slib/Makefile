# $NetBSD: Makefile,v 1.4 2020/03/08 16:49:13 wiz Exp $

SLIBVERSION=	3.2.6
DISTNAME=	guile-slib-${SLIBVERSION}
PKGNAME=	${DISTNAME:S/guile/guile22/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://swissnet.ai.mit.edu/~jaffer/SLIB.html
COMMENT=	SLIB glue files for guile

DEPENDS+=	slib>=${SLIBVERSION}:../../devel/slib

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
