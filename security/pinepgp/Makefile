# $NetBSD: Makefile,v 1.16 2012/10/23 18:16:50 asau Exp $
#

DISTNAME=		pinepgp-0.18.0
PKGREVISION=		3
CATEGORIES=		security mail
MASTER_SITES=		http://hany.sk/~hany/_data/pinepgp/	\
			http://terminus.sk/~hany/_data/pinepgp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://hany.sk/~hany/software/pinepgp/stable.html
COMMENT=		PGP display and sending filters for pine

DEPENDS+=		bash>=2:../../shells/bash2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		cat
CONFIGURE_ENV+=		CAT=${TOOLS_CAT:Q}

PINEPGP_USEGPG?=	yes
PINEPGP_USEPGP5?=	yes

.if !empty(PINEPGP_USEGPG:M[yY][eE][sS])
DEPENDS+=		gnupg>=1.2.3:../../security/gnupg
.endif

.if !empty(PINEPGP_USEPGP5:M[yY][eE][sS])
DEPENDS+=		pgp5>=5.0:../../security/pgp5
.endif

.include "../../mk/bsd.pkg.mk"
