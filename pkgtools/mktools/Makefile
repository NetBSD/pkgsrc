# $NetBSD: Makefile,v 1.1 2022/06/07 09:53:36 jperkin Exp $

PKGNAME=		mktools-20220607
CATEGORIES=		pkgtools sysutils

MAINTAINER=		jperkin@pkgsrc.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Collection of pkgsrc mk infrastructure tools
LICENSE=		modified-bsd

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	libexec/mktools

# Avoid any dependency cycles
CHECK_PERMS_SKIP=	*
CHECK_PORTABILITY_SKIP=	*
PKGSRC_LOCKTYPE=	none

do-extract:
	${CP} -R ${FILESDIR}/ ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
