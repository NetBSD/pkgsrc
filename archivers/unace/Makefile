# $NetBSD: Makefile,v 1.3 2001/07/16 10:21:15 jlam Exp $
#

DISTNAME=	unacepub
PKGNAME=	unace-1.2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.elf.stuba.sk/pub/pc/pack/ \
		ftp://sunsite.univie.ac.at/pub/compression/ftp.elf.stuba.sk/
EXTRACT_SUFX=	.zip

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.winace.com/
COMMENT=	Extract, list and test files in ACE archives

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes

DIST_SUBDIR=	unace-1.2
NO_WRKSUBDIR=	yes
MAKEFILE=	unix/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unace
	${INSTALL_MAN} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/unace

.include "../../mk/bsd.pkg.mk"
