# $NetBSD: Makefile,v 1.3 2010/01/27 20:02:56 joerg Exp $
#

DISTNAME=	Slay.1.2
PKGNAME=	slay-1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/admin/idle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	Unknown
COMMENT=	Kills a login shell and process(es) of a user

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slay ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
