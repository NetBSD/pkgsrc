# $NetBSD: Makefile,v 1.45 2008/06/20 01:09:08 joerg Exp $
#

DISTNAME=		geda-utils-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Set of utilities for gEDA

PKG_DESTDIR_SUPPORT=	user-destdir

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
USE_TOOLS+=		bash:run

# let (f)lex rebuild this file.  The distributed one doesn't
# always work.
post-patch:
	${RM} -f ${WRKSRC}/src/olib.c

REPLACE_BASH=		scripts/gnet_hier_verilog.sh
REPLACE_PYTHON=		scripts/tragesym
REPLACE_PERL+=		scripts/pads_backannotate \
			scripts/gschupdate \
			scripts/gsymfix.pl \
			scripts/gsymupdate \
			scripts/pcb_backannotate \
			scripts/refdes_renum \
			scripts/sarlacc_sym

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
