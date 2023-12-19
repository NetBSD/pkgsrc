# $NetBSD: Makefile,v 1.16 2023/12/19 12:32:24 zafer Exp $
#

DISTNAME=		srsh-1.3
CATEGORIES=		net
MASTER_SITES=		https://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Emulate rsh client behavior using ssh

.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
NO_CONFIGURE=		yes
MAKE_FLAGS+=		PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
