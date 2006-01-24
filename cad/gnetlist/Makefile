# $NetBSD: Makefile,v 1.37 2006/01/24 07:31:56 wiz Exp $
#

DISTNAME=		geda-gnetlist-${PKGVERSION}
PKGNAME=		gnetlist-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Netlist generation program

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols

.include "../../cad/geda/Makefile.common"

CONFLICTS+=		gEDA<19991011

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

# needs GNU m4 for the PCBboard and gsch2pcb netlisters
USE_TOOLS+=		gmake m4:run pkg-config
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

EVAL_PREFIX+=   PCBDIR=pcb
CONFIGURE_ARGS+=	--with-pcbm4dir=${PCBDIR}/share/pcb/m4
CONFIGURE_ARGS+=	--with-pcbconfdir=${PKG_SYSCONFDIR}/pcb

.include "../../cad/libgeda/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
