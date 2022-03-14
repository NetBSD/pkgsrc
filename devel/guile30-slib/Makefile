# $NetBSD: Makefile,v 1.1 2022/03/14 13:37:32 wiz Exp $

SLIBVERSION=	3.2.6
DISTNAME=	guile-slib-${SLIBVERSION}
PKGNAME=	${DISTNAME:S/guile/guile30/}
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://people.csail.mit.edu/jaffer/SLIB
COMMENT=	SLIB glue files for guile

GUILE_VERSION=	guile30
GUILE_DIR=	3.0
PLIST_SUBST+=	GUILE_DIR=${GUILE_DIR}

DEPENDS+=	slib>=${SLIBVERSION}:../../devel/slib

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

# See ../guile-slib for comments explaining the choice of paths and
# how this works.

INSTALLATION_DIRS=	guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR}

do-install:
	${RM} -f ${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR}/slib
	${LN} -sf ${PREFIX}/share/slib \
		${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR}/slib
	${RM} -f ${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR}/slibcat
	cd ${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR}/slib && \
		GUILE_LOAD_PATH=${PREFIX}/share \
		GUILE_IMPLEMENTATION_PATH=${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR} \
		${PREFIX}/guile/${GUILE_DIR}/bin/guile -q -c "(begin (use-modules (ice-9 slib)) (require 'new-catalog))"

.include "../../lang/${GUILE_VERSION}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
