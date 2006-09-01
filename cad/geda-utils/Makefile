# $NetBSD: Makefile,v 1.38 2006/09/01 12:00:43 dmcmahill Exp $
#

DISTNAME=		geda-utils-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Set of utilities for gEDA

BUILD_DEPENDS+=		geda-symbols-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_TOOLS+=		lex perl:run pkg-config

# let (f)lex rebuild this file.  The distributed one doesn't
# always work.
post-patch:
	${RM} -f ${WRKSRC}/src/olib.c

EVAL_PREFIX+=		PYDIR=python

REPLACE_INTERPRETER+=   python
REPLACE.python.old=	.*/bin/python
REPLACE.python.new=	${PYDIR}/bin/python
REPLACE_FILES.python=	scripts/tragesym

REPLACE_PERL+=		scripts/pads_backannotate \
			scripts/gschupdate \
			scripts/gsymfix.pl \
			scripts/gsymupdate \
			scripts/refdes_renum \
			scripts/sarlacc_sym

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
