# $NetBSD: Makefile,v 1.10 2001/06/04 17:00:18 jtb Exp $

DISTNAME=	unrar-2.71
CATEGORIES=	archivers
MASTER_SITES=	ftp://sunsite.univie.ac.at/pub/distfiles/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.rarsoft.com/
COMMENT=	Extract, view & test RAR archives

LICENSE=	unrar-license
RESTRICTED=	"Do not modify. Do not charge a fee for redistribution."
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

do-build:
	cd ${WRKSRC} && ${LINK.c} -o unrar -D_UNIX unrar.c

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unrar
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unrar ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} readme.txt license.txt \
		${PREFIX}/share/doc/unrar

.include "../../mk/bsd.pkg.mk"
