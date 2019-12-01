# $NetBSD: Makefile,v 1.15 2019/12/01 05:18:56 kim Exp $
#

DISTNAME=		srsh-1.3
CATEGORIES=		net
MASTER_SITES=		http://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Emulate rsh client behavior using ssh

.if !exists(/usr/bin/ssh)
DEPENDS+=		{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/openssh
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
NO_CONFIGURE=		yes
MAKE_FLAGS+=		PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
