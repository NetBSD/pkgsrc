# $NetBSD: Makefile,v 1.5 2005/03/24 21:13:00 wiz Exp $

DISTNAME=	pscan
PKGNAME=	pscan-1.3
CATEGORIES=	security devel
MASTER_SITES=	http://www.striker.ottawa.on.ca/~aland/pscan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.striker.ottawa.on.ca/~aland/pscan/
COMMENT=	Security C code scanner for misuse of format strings

BUILD_TARGET=	pscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pscan ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/find_formats.sh ${PREFIX}/bin/find_formats

.include "../../mk/bsd.pkg.mk"
