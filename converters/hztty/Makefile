# $NetBSD: Makefile,v 1.3 2003/07/21 16:36:12 martti Exp $

DISTNAME=	hztty-2.0
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.ifcss.org/pub/software/unix/convert/ \
		ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/convert/ \
		ftp://ftp.edu.tw/Chinese/ifcss/software/unix/convert/ \
		ftp://ftp.mpi-sb.mpg.de/pub/chinese/mirror/ftp.ifcss.org/software/unix/convert/

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=
COMMENT=	Turns a tty session between Big5/GB/HZ/Unicode

ALL_TARGET=	bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hztty ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hztty.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
