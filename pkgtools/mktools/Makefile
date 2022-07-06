# $NetBSD: Makefile,v 1.3 2022/07/06 05:03:09 dbj Exp $

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
IGNORE_CCACHE=		yes

do-extract:
	${CP} -R ${FILESDIR}/ ${WRKSRC}/

.include "../../mk/bsd.pkg.mk"
