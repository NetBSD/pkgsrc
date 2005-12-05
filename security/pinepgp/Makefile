# $NetBSD: Makefile,v 1.8 2005/12/05 20:50:58 rillig Exp $
#

DISTNAME=		pinepgp-0.18.0
PKGREVISION=		1
CATEGORIES=		security mail
MASTER_SITES=		http://www.megaloman.com/~hany/_data/pinepgp/	\
			http://terminus.sk/~hany/_data/pinepgp/		\
			http://www.mirrors.wiretapped.net/security/cryptography/apps/mail/pinepgp/

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www.megaloman.com/~hany/software/pinepgp/stable.html
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
