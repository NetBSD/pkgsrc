# $NetBSD: Makefile,v 1.12 2023/12/19 17:23:44 zafer Exp $
#

DISTNAME=		osname-2.0
CATEGORIES=		sysutils
MASTER_SITES=		https://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Print canonical name of operating system

NO_CONFIGURE=		yes
MAKE_FLAGS+=		PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
