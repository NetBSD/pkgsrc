# $NetBSD: Makefile,v 1.7 2022/03/10 07:42:32 wiz Exp $

SLIBVERSION=	3.2.6
DISTNAME=	guile-slib-${SLIBVERSION}
PKGNAME=	${DISTNAME:S/guile/guile22/}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://people.csail.mit.edu/jaffer/SLIB
COMMENT=	SLIB glue files for guile

GUILE_VERSION=	guile22
GUILE_DIR=	2.2
PLIST_SUBST+=	GUILE_DIR=${GUILE_DIR}

DEPENDS+=	slib>=${SLIBVERSION}:../../devel/slib

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	guile/${GUILE_DIR}/share/guile guile/${GUILE_DIR}/share/guile/site

do-install:
	${RM} -f ${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/slib
	${LN} -sf ${PREFIX}/share/slib \
		${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/slib
	${RM} -f ${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/slibcat
	cd ${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/slib && \
		GUILE_LOAD_PATH=${PREFIX}/share \
		GUILE_IMPLEMENTATION_PATH=${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site \
		${PREFIX}/guile/${GUILE_DIR}/bin/guile -q -c "(begin (use-modules (ice-9 slib)) (require 'new-catalog))"

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
