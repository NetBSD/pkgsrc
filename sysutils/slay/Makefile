# $NetBSD: Makefile,v 1.1.1.1 2004/06/07 18:05:43 xtraeme Exp $
#

DISTNAME=	Slay.1.2
PKGNAME=	slay-1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/admin/idle/}

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	Unknown
COMMENT=	Kills a login shell and process(es) of a user

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=		yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slay ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
