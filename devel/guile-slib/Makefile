# $NetBSD: Makefile,v 1.55 2022/03/10 16:32:25 gdt Exp $

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

# There is a residual problem where after slib is used (and scheme
# code is compiled), building the package again can result in "Unbound
# variable: module-export-all!".

INSTALLATION_DIRS=	guile/${GUILE_DIR}/share/guile/site/${GUILE_DIR}

# GUILE_LOAD_PATH enables (ice-9 slib) to find slib, needed because
# the symlink is in the DESTDIR but not yet in the installed system.
# GUILE_IMPLEMENTATION_PATH is an override to the slib catalog build
# procedure to write the catalog at that particular path instead of
# the default value of (%site-dir), which is
# /usr/pkg/guile/2.0/share/guile/site/2.0
# The RM commands are only needed if there is a failure in install and
# install is re-run.
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
