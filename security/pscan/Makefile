# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:32 jlam Exp $

DISTNAME=	pscan
PKGNAME=	pscan-1.3
CATEGORIES=	security devel
MASTER_SITES=	http://www.striker.ottawa.on.ca/~aland/pscan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.striker.ottawa.on.ca/~aland/pscan/
COMMENT=	Security C code scanner for misuse of format strings

BUILD_TARGET=	pscan

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pscan ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/find_formats.sh ${PREFIX}/bin/find_formats

.include "../../mk/bsd.pkg.mk"
