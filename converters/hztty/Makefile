# $NetBSD: Makefile,v 1.6 2005/01/19 16:11:41 tv Exp $

DISTNAME=	hztty-2.0
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/unix/convert/ \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/convert/ \
		ftp://ftp.edu.tw/Chinese/ifcss/software/unix/convert/ \
		ftp://ftp.mpi-sb.mpg.de/pub/chinese/mirror/ftp.ifcss.org/software/unix/convert/

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=
COMMENT=	Turns a tty session between Big5/GB/HZ/Unicode

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
BUILD_TARGET=	svr4
.else
BUILD_TARGET=	bsd
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hztty ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hztty.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
