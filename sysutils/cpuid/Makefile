# $NetBSD: Makefile,v 1.4 2006/03/04 21:30:40 jlam Exp $

DISTNAME=	cpuid-3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ka9q.net/code/cpuid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/directory/System_administration/Configuration/cpuid.html
COMMENT=	CPU identification feature

ONLY_FOR_PLATFORM=	*-*-i386

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} cpuid.c -o cpuid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuid ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
