# $NetBSD: Makefile,v 1.8.2.1 2002/06/23 18:39:56 jlam Exp $
#

DISTNAME=		geda-gnetlist-${PKGVERSION}
PKGNAME=		gnetlist-${PKGVERSION}
PKGREVISION=		2
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Netlist generation program

DIST_SUBDIR=		geda
PKGVERSION=		20020414

DEPENDS+=		libgeda-${PKGVERSION}:../../cad/libgeda
DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols
# needs GNU m4 for the PCBboard netlister
DEPENDS+=		m4-1.4:../../devel/m4

CONFLICTS+=		gEDA<19991011

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-patch:
	${MV} -f ${WRKSRC}/scheme/gnet-PCBboard.scm ${WRKSRC}/scheme/gnet-PCBboard.scm.bak
	${SED} 's;@pcb_confdir@;${PKG_SYSCONFDIR}/pcb;g' \
		${WRKSRC}/scheme/gnet-PCBboard.scm.bak > ${WRKSRC}/scheme/gnet-PCBboard.scm
	${RM} -f ${WRKSRC}/scheme/gnet-PCBboard.scm.bak

.include "../../mk/bsd.pkg.mk"
