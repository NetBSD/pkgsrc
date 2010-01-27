# $NetBSD: Makefile,v 1.12 2010/01/27 21:54:17 joerg Exp $

DISTNAME=	libdes-4.04b
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.psy.uq.oz.au/pub/Crypto/DES/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Small DES (Data Encryption Standard) lib & standalone program

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/des
CRYPTO=		YES

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man3

.include "../../mk/bsd.pkg.mk"
