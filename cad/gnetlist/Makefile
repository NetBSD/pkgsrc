# $NetBSD: Makefile,v 1.43 2006/09/17 17:36:35 rillig Exp $
#

DISTNAME=		geda-gnetlist-${PKGVERSION}
PKGNAME=		gnetlist-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Netlist generation program

DEPENDS+=		geda-symbols-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-symbols

.include "../../cad/geda/Makefile.common"

CONFLICTS+=		gEDA<19991011

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

# needs GNU m4 for the PCBboard and gsch2pcb netlisters
USE_TOOLS+=		gmake m4:run pkg-config

EVAL_PREFIX+=   PCBDIR=pcb
CONFIGURE_ARGS+=	--with-pcbm4dir=${PCBDIR}/share/pcb/m4
CONFIGURE_ARGS+=	--with-pcbconfdir=${PKG_SYSCONFDIR}/pcb

REPLACE_SH+=		scripts/sch2eaglepos.sh
USE_TOOLS+=		sh:run

.include "../../cad/libgeda/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
