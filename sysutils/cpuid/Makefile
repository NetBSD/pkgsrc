# $NetBSD: Makefile,v 1.11 2021/01/13 08:00:21 wiz Exp $

DISTNAME=	cpuid-3.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ka9q.net/code/cpuid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://directory.fsf.org/project/cpuid/
COMMENT=	CPU identification feature

ONLY_FOR_PLATFORM=	*-*-i386
ONLY_FOR_PLATFORM+=	*-*-x86_64

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} cpuid.c -o cpuid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuid ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
