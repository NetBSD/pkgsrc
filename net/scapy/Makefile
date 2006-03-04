# $NetBSD: Makefile,v 1.3 2006/03/04 21:30:24 jlam Exp $
#

DISTNAME=		scapy-1.0.0
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.secdev.org/projects/scapy/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
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
