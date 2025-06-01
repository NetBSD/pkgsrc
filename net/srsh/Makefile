# $NetBSD: Makefile,v 1.17 2025/06/01 10:58:55 vins Exp $
#

DISTNAME=		srsh-1.3
CATEGORIES=		net
MASTER_SITES=		https://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Emulate rsh client behavior using ssh

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
NO_CONFIGURE=		yes
MAKE_FLAGS+=		PREFIX=${PREFIX}

.include "../../security/openssh/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
