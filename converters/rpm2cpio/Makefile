# $NetBSD: Makefile,v 1.30 2015/02/27 21:30:50 tnn Exp $

DISTNAME=	rpm2cpio-1.3
CATEGORIES=	converters
MASTER_SITES=	-https://svnweb.freebsd.org/ports/head/archivers/rpm2cpio/files/rpm2cpio?revision=340851&view=co
EXTRACT_SUFX=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://svnweb.freebsd.org/ports/head/archivers/rpm2cpio/
COMMENT=	Convert .rpm files for extraction with cpio, needs just perl

WRKSRC=		${WRKDIR}

USE_TOOLS+=	perl:run
REPLACE_PERL=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin

# There is nothing to build
do-build:

# conflicts with rpm package, which also contains a rpm2cpio
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PKGNAME_NOREV} ${DESTDIR}${PREFIX}/bin/rpm2cpio.pl

.include "../../mk/bsd.pkg.mk"
