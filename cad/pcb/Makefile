# $NetBSD: Makefile,v 1.14 2002/06/27 16:46:30 agc Exp $
# FreeBSD Id: Makefile,v 1.19 1998/10/31 18:05:31 jseger Exp
#

DISTNAME=	pcb-1.6.3
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.linuxppc.org/pub/linuxppc/users/harry/PCB/ \
		ftp://ftp.uni-ulm.de/pub/pcb/mirror/
EXTRACT_SUFX=	.tgz
DISTFILES=	pcb-1.6.3.tgz \
		pcb-docs-1.6.3.tar.gz

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://bach.ece.jhu.edu/~haceaton/pcb/
COMMENT=	X11 interactive printed circuit board layout system

DEPENDS+=	m4-1.4:../../devel/m4

USE_IMAKE=	yes

INFO_FILES=	pcb.info

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL

PCB_CONFDIR=	${PKG_SYSCONFDIR}/pcb
MESSAGE_SUBST+=	PCB_CONFDIR=${PCB_CONFDIR}
# avoid picking up any user config files during the build
MAKE_ENV+=	HOME=${WRKSRC}

post-patch:
	${MV} -f ${WRKSRC}/config.h  ${WRKSRC}/config.h.bak
	${SED} 's;@pkg_sysconfdir@;${PCB_CONFDIR};g' ${WRKSRC}/config.h.bak > ${WRKSRC}/config.h

pre-install:
	${SED} 's;@pkg_sysconfdir@;${PKG_SYSCONFDIR};g' ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/index.html ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/pcb.html ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/pcb.info ${PREFIX}/info/
	${INSTALL_MAN} ${WRKSRC}/doc/pcb.ps ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/refcard.ps ${PREFIX}/share/doc/pcb/
	${INSTALL_DATA_DIR} ${PCB_CONFDIR}
	if [ ! -f "${PCB_CONFDIR}/local.inc" ]; then \
		${ECHO} "# list your local includes here" > ${PCB_CONFDIR}/local.inc ; \
	fi
	${MV} -f ${X11PREFIX}/lib/X11/pcb/m4/common.m4 ${X11PREFIX}/lib/X11/pcb/m4/common.m4.bak
	${AWK} '/^divert\(0\)dnl/ { \
			printf("include(${PCB_CONFDIR}/local.inc)\n"); \
			printf("sinclude(site-config.inc)\n"); \
			printf("sinclude(user-config.inc)\n"); \
			printf("sinclude(proj-config.inc)\n"); \
			} \
		{gsub(/^include\(/,"include(${X11PREFIX}/lib/X11/pcb/m4/"); print } ' \
		${X11PREFIX}/lib/X11/pcb/m4/common.m4.bak > ${X11PREFIX}/lib/X11/pcb/m4/common.m4
	${RM} -f ${X11PREFIX}/lib/X11/pcb/m4/common.m4.bak

.include "../../mk/texinfo.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
