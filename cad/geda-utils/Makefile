# $NetBSD: Makefile,v 1.28 2005/04/11 21:45:01 tv Exp $
#

DISTNAME=		geda-utils-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Set of utilities for gEDA

BUILD_DEPENDS+=		geda-symbols>=${PKGVERSION}:../../cad/geda-symbols
.if !exists(/usr/bin/lex) && !exists(/usr/bin/flex)
BUILD_DEPENDS+=		flex-[0-9]*:../../devel/flex
EVAL_PREFIX+=		LEXDIR=flex
LEX=			${LEXDIR}/bin/flex
.endif

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_PERL5=		YES

# let (f)lex rebuild this file.  The distributed one doesn't
# always work.
post-patch:
	${RM} -f ${WRKSRC}/src/olib.c

EVAL_PREFIX+=		PYDIR=python

REPLACE_INTERPRETER+=   python
_REPLACE.python.old=	.*/bin/python
_REPLACE.python.new=	${PYDIR}/bin/python
_REPLACE_FILES.python=	scripts/tragesym

REPLACE_PERL+=		scripts/pads_backannotate \
			scripts/gschupdate \
			scripts/gsymfix.pl \
			scripts/gsymupdate \
			scripts/refdes_renum \
			scripts/sarlacc_sym

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
