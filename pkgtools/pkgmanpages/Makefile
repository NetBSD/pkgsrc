# $NetBSD: Makefile,v 1.3 2001/02/17 17:51:30 wiz Exp $
#

DISTNAME=	pkgmanpages-19991222
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.netbsd.org/
COMMENT=	manual page(s) for the packages collection

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PREFIX=		/usr/share
.endif

do-install:
	${BSD_INSTALL_MAN} ${WRKSRC}/packages.7 ${PREFIX}/man/man7

.include "../../mk/bsd.pkg.mk"
