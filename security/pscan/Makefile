# $NetBSD: Makefile,v 1.14 2020/02/04 17:25:59 rillig Exp $

DISTNAME=	pscan
PKGNAME=	pscan-1.3
CATEGORIES=	security devel
# Has only unversioned distfile.
# The 2015 tar.gz is essentially equal to the 2001 version.
#MASTER_SITES=	# http://deployingradius.com/pscan/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://deployingradius.com/pscan/ # no https available
COMMENT=	Security C code scanner for misuse of format strings
LICENSE=	gnu-gpl-v2

BUILD_TARGET=	pscan

USE_TOOLS+=	lex

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pscan ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/find_formats.sh ${DESTDIR}${PREFIX}/bin/find_formats

.include "../../mk/bsd.pkg.mk"
