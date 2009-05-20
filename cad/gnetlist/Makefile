# $NetBSD: Makefile,v 1.48 2009/05/20 00:58:06 wiz Exp $
#

DISTNAME=		geda-gnetlist-${PKGVERSION}
PKGNAME=		gnetlist-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Netlist generation program

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		geda-symbols-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-symbols

.include "../../cad/geda/Makefile.common"

CONFLICTS+=		gEDA<19991011

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

# needs GNU m4 for the PCBboard and gsch2pcb netlisters
USE_TOOLS+=		gmake m4:run pkg-config

EVAL_PREFIX+=	PCBDIR=pcb
CONFIGURE_ARGS+=	--with-pcbm4dir=${PCBDIR}/share/pcb/m4
CONFIGURE_ARGS+=	--with-pcbconfdir=${PKG_SYSCONFDIR}/pcb

REPLACE_SH+=		scripts/sch2eaglepos.sh
USE_TOOLS+=		sh:run

.include "../../cad/libgeda/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
