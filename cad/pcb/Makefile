# $NetBSD: Makefile,v 1.7 2000/08/31 14:55:29 dmcmahill Exp $
# FreeBSD Id: Makefile,v 1.19 1998/10/31 18:05:31 jseger Exp
#

DISTNAME=	pcb-1.6.3
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.linuxppc.org/pub/linuxppc/users/harry/PCB/ \
		ftp://ftp.uni-ulm.de/pub/pcb/mirror/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bach.ece.jhu.edu/~haceaton/pcb/

DEPENDS+=	m4-1.4:../../devel/m4

USE_IMAKE=	yes

INFO_FILES=	pcb.info

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${FILESDIR}/index.html ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${FILESDIR}/pcb.html ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${FILESDIR}/pcb.info ${PREFIX}/info/
	${INSTALL_MAN} ${FILESDIR}/pcb.ps ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${FILESDIR}/refcard.ps ${PREFIX}/share/doc/pcb/

.include "../../mk/bsd.pkg.mk"
