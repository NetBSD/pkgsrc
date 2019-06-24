# $NetBSD: Makefile,v 1.10 2019/06/24 10:59:41 nia Exp $

DISTNAME=	cpuid-3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ka9q.net/code/cpuid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://directory.fsf.org/project/cpuid/
COMMENT=	CPU identification feature

ONLY_FOR_PLATFORM=	*-*-i386
ONLY_FOR_PLATFORM+=	*-*-x86_64

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} cpuid.c -o cpuid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuid ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
