# $NetBSD: Makefile,v 1.22 2011/03/11 10:10:32 zafer Exp $

DISTNAME=	unlzx.c
PKGNAME=	unlzx-1.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/misc/unix/

EXTRACT_SUFX=	.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extracts .lzx archives from Amiga systems

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o unlzx unlzx.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unlzx ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
