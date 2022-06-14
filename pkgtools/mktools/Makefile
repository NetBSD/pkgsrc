# $NetBSD: Makefile,v 1.2 2022/06/14 08:45:33 jperkin Exp $

PKGNAME=		mktools-20220614
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
