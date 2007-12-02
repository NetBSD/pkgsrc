# $NetBSD: Makefile,v 1.8 2007/12/02 11:54:49 wiz Exp $

DISTNAME=	hztty-2.0
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/convert/

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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hztty ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hztty.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
