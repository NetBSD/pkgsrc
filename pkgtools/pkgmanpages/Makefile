# $NetBSD: Makefile,v 1.9 2004/01/20 12:23:58 agc Exp $
#

DISTNAME=	pkgmanpages-19991222
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	Manual page(s) for the packages collection

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PREFIX=		/usr/share
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/packages.7 ${PREFIX}/man/man7

.include "../../mk/bsd.pkg.mk"
