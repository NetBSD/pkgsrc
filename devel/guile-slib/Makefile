# $NetBSD: Makefile,v 1.54 2022/03/10 14:29:04 gdt Exp $

SLIBVERSION=	3.2.6
DISTNAME=	guile-slib-${SLIBVERSION}
PKGREVISION=	6
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

# Instructions at
#   https://www.gnu.org/software/guile/docs/docs-2.0/guile-ref/SLIB-installation.html
# say
#   ln -s /usr/local/lib/slib /usr/local/share/guile/2.0/slib
# However, slib's default catalog location is guile/site/2.0, so we
# use that.

INSTALLATION_DIRS=	guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR}

# GUILE_LOAD_PATH enables (ice-9 slib) to find slib, needed because
# the symlink is in the DESTDIR but not yet in the installed system.
# GUILE_IMPLEMENTATION_PATH is an override to the slib catalog build
# procedure to write the catalog at that particular path instead of
# the default value of (%site-dir), which is
# /usr/pkg/guile/2.0/share/guile/site/2.0
do-install:
	${LN} -sf ${PREFIX}/share/slib \
		${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR}/slib
	cd ${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR}/slib && \
		GUILE_LOAD_PATH=${PREFIX}/share \
		GUILE_IMPLEMENTATION_PATH=${DESTDIR}${PREFIX}/guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR} \
		${PREFIX}/guile/${GUILE_DIR}/bin/guile -q -c "(begin (use-modules (ice-9 slib)) (require 'new-catalog))"


.include "../../lang/${GUILE_VERSION}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
