# $NetBSD: Makefile,v 1.1.1.1 2005/08/10 13:54:58 drochner Exp $
#

DISTNAME=		scapy-1.0.0
CATEGORIES=		net
MASTER_SITES=		http://www.secdev.org/projects/scapy/files/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.secdev.org/projects/scapy/
COMMENT=		Interactive packet manipulation program

NO_BUILD=	yes
PYTHON_VERSIONS_ACCEPTED=	23 24
PYTHON_PATCH_SCRIPTS=	scapy.py
MANCOMPRESSED=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scapy.py ${PREFIX}/bin/scapy
	${INSTALL_MAN} ${WRKSRC}/scapy.1.gz ${PREFIX}/man/man1

.include "../../lang/python/application.mk"
.include "../../net/py-libpcap/buildlink3.mk"
.include "../../net/py-libdnet/buildlink3.mk"
.include "../../devel/py-readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
