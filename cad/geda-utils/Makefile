# $NetBSD: Makefile,v 1.25 2004/10/03 00:13:12 tv Exp $
#

DISTNAME=		geda-utils-${PKGVERSION}
PKGREVISION=	1
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

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
USE_BUILDLINK3=		YES
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
			scripts/gsymupdate \
			scripts/refdes_renum \
			scripts/sarlacc_sym

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
