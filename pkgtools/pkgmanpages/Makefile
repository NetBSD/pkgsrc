# $NetBSD: Makefile,v 1.5 2002/02/06 16:58:15 jlam Exp $
#

DISTNAME=	pkgmanpages-19991222
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/
COMMENT=	manual page(s) for the packages collection

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PREFIX=		/usr/share
.endif

do-install:
	${INSTALL_MAN} ${WRKSRC}/packages.7 ${PREFIX}/man/man7

.include "../../mk/bsd.pkg.mk"
