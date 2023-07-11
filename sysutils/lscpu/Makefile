# $NetBSD: Makefile,v 1.3 2023/07/11 19:32:00 vins Exp $

DISTNAME=	lscpu-1.2.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=NanXiao/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NanXiao/lscpu/
COMMENT=	The lscpu for BSD
LICENSE=	modified-bsd

.for bsd in FreeBSD OpenBSD NetBSD DragonFly Darwin
ONLY_FOR_PLATFORM+=	${bsd}-*-i386
ONLY_FOR_PLATFORM+=	${bsd}-*-x86_64
.endfor

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lscpu		\
		${DESTDIR}${PREFIX}/bin/lscpu
	${INSTALL_MAN}     ${WRKSRC}/lscpu.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
