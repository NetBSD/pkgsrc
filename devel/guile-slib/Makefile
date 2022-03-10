# $NetBSD: Makefile,v 1.52 2022/03/10 13:32:36 gdt Exp $

SLIBVERSION=	3.2.6
DISTNAME=	guile-slib-${SLIBVERSION}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://people.csail.mit.edu/jaffer/SLIB
COMMENT=	SLIB glue files for guile

GUILE_VERSION=	guile20
GUILE_DIR=	2.0
PLIST_SUBST+=	GUILE_DIR=${GUILE_DIR}

DEPENDS+=	slib>=${SLIBVERSION}:../../devel/slib

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	guile/${GUILE_DIR}/share/guile guile/${GUILE_DIR}/share/guile/site

# Instructions at
#   https://www.gnu.org/software/guile/docs/docs-2.2/guile-ref/SLIB-installation.html
# say
#   ln -s /usr/local/lib/slib /usr/local/share/guile/2.2/slib
# We were using site instead of 2.2 in previous guile-slib packages.

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/${GUILE_DIR}
	${LN} -sf ${PREFIX}/share/slib \
		${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/${GUILE_DIR}/slib
	cd ${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/${GUILE_DIR} && \
		GUILE_LOAD_PATH=${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/${GUILE_DIR} \
		${PREFIX}/guile/${GUILE_DIR}/bin/guile -q -c "(begin (use-modules (ice-9 slib)) (require 'new-catalog))"

# historical - does not seem to be used in 2.2
#		GUILE_IMPLEMENTATION_PATH=${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share \

.include "../../lang/${GUILE_VERSION}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
