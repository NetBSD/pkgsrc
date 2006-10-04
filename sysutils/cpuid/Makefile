# $NetBSD: Makefile,v 1.5 2006/10/04 21:59:34 wiz Exp $

DISTNAME=	cpuid-3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ka9q.net/code/cpuid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/System_administration/Configuration/cpuid.html
COMMENT=	CPU identification feature

ONLY_FOR_PLATFORM=	*-*-i386

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} cpuid.c -o cpuid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuid ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
