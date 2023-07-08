# $NetBSD: Makefile,v 1.2 2023/07/08 21:39:27 vins Exp $

DISTNAME=	lscpu-1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=NanXiao/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NanXiao/lscpu/
COMMENT=	The lscpu for BSD
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM+=	FreeBSD-*-* OpenBSD-*-* NetBSD-*-*
ONLY_FOR_PLATFORM+=	DragonFly-*-* Darwin-*-*

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lscpu		\
		${DESTDIR}${PREFIX}/bin/lscpu
	${INSTALL_MAN}     ${WRKSRC}/lscpu.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
