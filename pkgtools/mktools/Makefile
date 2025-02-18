# $NetBSD: Makefile,v 1.5 2025/02/18 15:20:24 wiz Exp $

PKGNAME=		mktools-20250213
CATEGORIES=		pkgtools sysutils

MAINTAINER=		pkgsrc-users@pkgsrc.org
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
