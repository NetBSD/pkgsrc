# $NetBSD: Makefile,v 1.5 2014/10/09 14:07:00 wiz Exp $
#

DISTNAME=	Slay.1.2
PKGNAME=	slay-1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/admin/idle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	Unknown
COMMENT=	Kills a login shell and process(es) of a user

NO_BUILD=		yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slay ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
