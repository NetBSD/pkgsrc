# $NetBSD: Makefile,v 1.27 2004/10/03 00:13:12 tv Exp $
#

DISTNAME=		geda-gnetlist-${PKGVERSION}
PKGNAME=		gnetlist-${PKGVERSION}
PKGREVISION=	1
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Netlist generation program

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols
# needs GNU m4 for the PCBboard netlister
DEPENDS+=		m4>=1.4:../../devel/m4

.include "../../cad/geda/Makefile.common"

CONFLICTS+=		gEDA<19991011

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

EVAL_PREFIX+=   PCBDIR=pcb
M4DIR=	${LOCALBASE}

post-patch:
.for f in gnet-PCBboard.scm gnet-gsch2pcb.scm
	${MV} -f ${WRKSRC}/scheme/${f} ${WRKSRC}/scheme/${f}.bak
	${SED} -e 's;@M4@;${M4DIR}/bin/${GNU_PROGRAM_PREFIX}m4;g' \
	       -e 's;@pcb_confdir@;${PKG_SYSCONFDIR}/pcb;g' \
	       -e 's;@pcb_m4dir@;${PCBDIR}/share/pcb/m4;g' \
		${WRKSRC}/scheme/${f}.bak > ${WRKSRC}/scheme/${f}
	${RM} -f ${WRKSRC}/scheme/${f}.bak
.endfor

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
