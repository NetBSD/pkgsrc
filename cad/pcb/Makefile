# $NetBSD: Makefile,v 1.2 1998/11/19 15:40:45 agc Exp $
# FreeBSD Id: Makefile,v 1.19 1998/10/31 18:05:31 jseger Exp
#

DISTNAME=	pcb-1.6.3
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.linuxppc.org/pub/linuxppc/users/harry/PCB/ \
		ftp://ftp.uni-ulm.de/pub/pcb/mirror/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org

BUILD_DEPENDS=	texindex:../../print/teTeX
DEPENDS+=	m4-1.4:../../devel/m4

USE_IMAKE=	yes

.include "../../mk/bsd.pkg.mk"
