# $NetBSD: Makefile,v 1.20 2003/12/13 00:45:21 wiz Exp $
#

DISTNAME=		geda-utils-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Set of utilites for gEDA

BUILD_DEPENDS+=		geda-symbols>=${PKGVERSION}:../../cad/geda-symbols
.if !exists(/usr/bin/lex) && !exists(/usr/bin/flex)
BUILD_DEPENDS+=		flex-[0-9]*:../../devel/flex
EVAL_PREFIX+=		LEXDIR=flex
LEX=			${LEXDIR}/bin/flex
.endif

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		20030901

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
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

.include "../../cad/libgeda/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
