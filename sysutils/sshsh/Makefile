# $NetBSD: Makefile,v 1.10 2023/12/19 17:25:32 zafer Exp $
#

DISTNAME=		sshsh-1.0
CATEGORIES=		sysutils
MASTER_SITES=		https://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Run a new shell with an SSH identity

NO_CONFIGURE=		yes
MAKE_FLAGS+=		PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
