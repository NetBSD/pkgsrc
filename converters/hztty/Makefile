# $NetBSD: Makefile,v 1.13 2016/02/25 12:56:10 jperkin Exp $

DISTNAME=	hztty-2.0
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/convert/

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=
COMMENT=	Turns a tty session between Big5/GB/HZ/Unicode

BUILD_TARGET.Interix=	svr4
BUILD_TARGET.Linux=	linux
BUILD_TARGET.*=	bsd

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hztty ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hztty.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
