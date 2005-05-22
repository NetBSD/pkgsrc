# $NetBSD: Makefile,v 1.32 2005/05/22 20:51:45 jlam Exp $
#

DISTNAME=		geda-gnetlist-${PKGVERSION}
PKGNAME=		gnetlist-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Netlist generation program

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols
# needs GNU m4 for the PCBboard netlister
USE_TOOLS+=		gm4
TOOLS_DEPMETHOD.gm4=	DEPENDS

.include "../../cad/geda/Makefile.common"

CONFLICTS+=		gEDA<19991011

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

EVAL_PREFIX+=   PCBDIR=pcb

post-patch:
.for f in gnet-PCBboard.scm gnet-gsch2pcb.scm
	${MV} -f ${WRKSRC}/scheme/${f} ${WRKSRC}/scheme/${f}.bak
	${SED} -e 's;@M4@;${TOOLS_M4:Q};g' \
	       -e 's;@pcb_confdir@;${PKG_SYSCONFDIR}/pcb;g' \
	       -e 's;@pcb_m4dir@;${PCBDIR}/share/pcb/m4;g' \
		${WRKSRC}/scheme/${f}.bak > ${WRKSRC}/scheme/${f}
	${RM} -f ${WRKSRC}/scheme/${f}.bak
.endfor

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
