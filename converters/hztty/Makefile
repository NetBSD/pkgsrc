# $NetBSD: Makefile,v 1.9 2008/03/03 05:51:08 jlam Exp $

DISTNAME=	hztty-2.0
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.cuhk.hk/pub/chinese/ifcss/software/unix/convert/

MAINTAINER=	rxg@NetBSD.org
#HOMEPAGE=
COMMENT=	Turns a tty session between Big5/GB/HZ/Unicode

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
BUILD_TARGET=	svr4
.else
BUILD_TARGET=	bsd
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hztty ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/hztty.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
