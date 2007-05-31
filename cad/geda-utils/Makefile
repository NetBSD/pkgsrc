# $NetBSD: Makefile,v 1.42 2007/05/31 12:48:33 dmcmahill Exp $
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
# for gsch2pcb
EVAL_PREFIX+=		PCBDIR=pcb
CONFIGURE_ARGS+=	--with-pcb-datadir=${PCBDIR}/share
USE_TOOLS+=		gawk:run lex perl:run pkg-config

# for gnet_hier_verilog.sh.  It looks to be fairly bash
# dependent
DEPENDS+=		bash-[0-9]*:../../shells/bash

# let (f)lex rebuild this file.  The distributed one doesn't
# always work.
post-patch:
	${RM} -f ${WRKSRC}/src/olib.c

EVAL_PREFIX+=		PYDIR=python

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	.*/bin/python
REPLACE.python.new=	${PYDIR}/bin/python
REPLACE_FILES.python=	scripts/tragesym

EVAL_PREFIX+=		BASHDIR=bash
REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	.*/bin/bash
REPLACE.bash.new=	${BASHDIR}/bin/bash
REPLACE_FILES.bash=	scripts/gnet_hier_verilog.sh

REPLACE_PERL+=		scripts/pads_backannotate \
			scripts/gschupdate \
			scripts/gsymfix.pl \
			scripts/gsymupdate \
			scripts/refdes_renum \
			scripts/sarlacc_sym

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
