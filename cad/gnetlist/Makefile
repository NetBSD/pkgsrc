# $NetBSD: Makefile,v 1.13 2002/12/13 05:19:49 dmcmahill Exp $
#

DISTNAME=		geda-gnetlist-${PKGVERSION}
PKGNAME=		gnetlist-${PKGVERSION}
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Netlist generation program

DIST_SUBDIR=		geda
PKGVERSION=		20021103

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols
# needs GNU m4 for the PCBboard netlister
DEPENDS+=		m4-1.4:../../devel/m4

CONFLICTS+=		gEDA<19991011

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-patch:
	${MV} -f ${WRKSRC}/scheme/gnet-PCBboard.scm ${WRKSRC}/scheme/gnet-PCBboard.scm.bak
	${SED} 's;@pcb_confdir@;${PKG_SYSCONFDIR}/pcb;g' \
		${WRKSRC}/scheme/gnet-PCBboard.scm.bak > ${WRKSRC}/scheme/gnet-PCBboard.scm
	${RM} -f ${WRKSRC}/scheme/gnet-PCBboard.scm.bak

.include "../../cad/libgeda/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
