# $NetBSD: Makefile,v 1.23 2006/01/21 18:57:40 jlam Exp $

DISTNAME=	rpm2cpio
PKGNAME=	rpm2cpio-1.1
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	http://www.iagora.com/~espel/
EXTRACT_SUFX=	# none

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.iagora.com/~espel/hacks.html
COMMENT=	Convert .rpm files for extraction with cpio, needs just perl

WRKSRC=		${WRKDIR}

DIST_SUBDIR=	${PKGNAME_NOREV}
USE_TOOLS+=	perl:run
REPLACE_PERL=	rpm2cpio

INSTALLATION_DIRS=	bin

# There is nothing to build
do-build:

# conflicts with rpm package, which also contains a rpm2cpio
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/rpm2cpio ${PREFIX}/bin/rpm2cpio.pl

.include "../../mk/bsd.pkg.mk"
