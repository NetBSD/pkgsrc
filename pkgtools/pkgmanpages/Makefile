# $NetBSD: Makefile,v 1.6 2003/03/29 12:42:12 jmmv Exp $
#

DISTNAME=	pkgmanpages-19991222
WRKSRC=		${WRKDIR}
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/
COMMENT=	manual page(s) for the packages collection

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PREFIX=		/usr/share
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/packages.7 ${PREFIX}/man/man7

.include "../../mk/bsd.pkg.mk"
