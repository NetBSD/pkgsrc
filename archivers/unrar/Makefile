# $NetBSD: Makefile,v 1.13 2002/08/25 21:49:25 jlam Exp $

DISTNAME=	unrarsrc
PKGNAME=	unrar-3.0
CATEGORIES=	archivers
MASTER_SITES=	http://www.rarlab.com/rar/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.rarlab.com/
COMMENT=	Extract, view & test RAR archives

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}

ALL_TARGET=	makeunrar
MAKEFILE=	makefile.gcc

LICENSE=	unrar-license
RESTRICTED=	"Do not modify. Do not charge a fee for redistribution."
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

USE_BUILDLINK2=	# defined

do-build:
	cd ${WRKSRC} && ${BUILDLINK_CC} ${CFLAGS} -o unrar -D_UNIX unrar.c

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unrar
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unrar ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} readme.txt license.txt \
		${PREFIX}/share/doc/unrar

.include "../../mk/bsd.pkg.mk"
