# $NetBSD: Makefile,v 1.1.1.1 2003/07/03 10:21:31 agc Exp $

DISTNAME=	cpuid-3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ka9q.net/code/cpuid/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.gnu.org/directory/System_administration/Configuration/cpuid.html
COMMENT=	CPU identification feature

ONLY_FOR_PLATFORM=	*-*-i386

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} cpuid.c -o cpuid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuid ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
