# $NetBSD: Makefile,v 1.7 2010/01/27 18:24:33 joerg Exp $

DISTNAME=	cpuid-3.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ka9q.net/code/cpuid/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://directory.fsf.org/System_administration/Configuration/cpuid.html
COMMENT=	CPU identification feature

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	*-*-i386
ONLY_FOR_PLATFORM+=	*-*-x86_64

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} cpuid.c -o cpuid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpuid ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
