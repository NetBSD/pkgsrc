# $NetBSD: Makefile,v 1.10 2002/02/18 15:14:03 seb Exp $
# FreeBSD Id: Makefile,v 1.19 1998/10/31 18:05:31 jseger Exp
#

DISTNAME=	pcb-1.6.3
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

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/index.html ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/pcb.html ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/pcb.info ${PREFIX}/info/
	${INSTALL_MAN} ${WRKSRC}/doc/pcb.ps ${PREFIX}/share/doc/pcb/
	${INSTALL_MAN} ${WRKSRC}/doc/refcard.ps ${PREFIX}/share/doc/pcb/

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
