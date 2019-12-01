# $NetBSD: Makefile,v 1.9 2019/12/01 05:18:56 kim Exp $
#

DISTNAME=		sshsh-1.0
CATEGORIES=		sysutils
MASTER_SITES=		http://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Run a new shell with an SSH identity

NO_CONFIGURE=		yes
MAKE_FLAGS+=		PREFIX=${PREFIX}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
