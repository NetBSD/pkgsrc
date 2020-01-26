# $NetBSD: Makefile,v 1.4 2020/01/26 17:31:59 rillig Exp $
#

PKGNAME=	osabi-${OPSYS}-${OS_VERSION}
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Operating System version dummy-package

META_PACKAGE=	yes
FILES_SUBST+=	UNAME=${UNAME:Q} PKG_ADMIN=${PKG_ADMIN:Q}

.include "../../mk/bsd.pkg.mk"
