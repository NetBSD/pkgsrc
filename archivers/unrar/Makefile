# $NetBSD: Makefile,v 1.15 2002/10/17 16:28:31 wiz Exp $

DISTNAME=	unrarsrc
PKGNAME=	unrar-3.01
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.rarlab.com/
COMMENT=	Extract, view & test RAR archives

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}/unrar

ALL_TARGET=	makeunrar
MAKEFILE=	makefile.gcc

LICENSE=	unrar-license
RESTRICTED=	"Do not modify. Do not charge a fee for redistribution."
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

USE_BUILDLINK2=	# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unrar
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unrar ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} readme.txt license.txt \
		${PREFIX}/share/doc/unrar

.include "../../mk/bsd.pkg.mk"
