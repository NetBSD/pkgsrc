# $NetBSD: Makefile,v 1.4 2000/08/03 18:19:55 rh Exp $
# FreeBSD Id: Makefile,v 1.19 1998/10/31 18:05:31 jseger Exp
#

DISTNAME=	pcb-1.6.3
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.linuxppc.org/pub/linuxppc/users/harry/PCB/ \
		ftp://ftp.uni-ulm.de/pub/pcb/mirror/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

DEPENDS+=	m4-1.4:../../devel/m4
.if make(misc-depends)
DEPENDS+=	teTeX-bin>=1.0.7:../../print/teTeX-bin
.endif

USE_IMAKE=	yes

.include "../../mk/bsd.pkg.mk"
