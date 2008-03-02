# $NetBSD: Makefile,v 1.21 2008/03/02 03:48:37 jlam Exp $

DISTNAME=	unlzx.c
PKGNAME=	unlzx-1.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://de.aminet.net/misc/unix/ \
		ftp://us.aminet.net/pub/aminet/misc/unix/
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
