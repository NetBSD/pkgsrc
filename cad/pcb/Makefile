# $NetBSD: Makefile,v 1.11 2002/05/31 19:56:19 dmcmahill Exp $
# FreeBSD Id: Makefile,v 1.19 1998/10/31 18:05:31 jseger Exp
#

DISTNAME=	pcb-1.6.3
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.linuxppc.org/pub/linuxppc/users/harry/PCB/ \
		ftp://ftp.uni-ulm.de/pub/pcb/mirror/
EXTRACT_SUFX=	.tgz
DISTFILES=	pcb-1.6.3.tgz \
		pcb-docs-1.6.3.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bach.ece.jhu.edu/~haceaton/pcb/
COMMENT=	X11 interactive printed circuit board layout system

DEPENDS+=	m4-1.4:../../devel/m4

USE_IMAKE=	yes

INFO_FILES=	pcb.info

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL

pre-install:
	${SED} 's;@pkg_sysconfdir@;${PKG_SYSCONFDIR};g' ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/index.html ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/pcb.html ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/pcb.info ${PREFIX}/info/
	${INSTALL_MAN} ${WRKSRC}/doc/pcb.ps ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/refcard.ps ${PREFIX}/share/doc/pcb/
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/pcb
	if [ ! -f "${PKG_SYSCONFDIR}/pcb/local.inc" ]; then \
		${ECHO} "# list your local includes here" > ${PKG_SYSCONFDIR}/pcb/local.inc ; \
	fi
	${MV} -f ${X11BASE}/lib/X11/pcb/m4/common.m4 ${X11BASE}/lib/X11/pcb/m4/common.m4.bak
	${AWK} '/^divert\(0\)dnl/ {print "include(${PKG_SYSCONFDIR}/pcb/local.inc)"} \
		{gsub(/^include\(/,"include(${X11BASE}/lib/X11/pcb/m4/"); print } ' \
		${X11BASE}/lib/X11/pcb/m4/common.m4.bak > ${X11BASE}/lib/X11/pcb/m4/common.m4
	${RM} -f ${X11BASE}/lib/X11/pcb/m4/common.m4.bak

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
