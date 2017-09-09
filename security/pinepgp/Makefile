# $NetBSD: Makefile,v 1.19 2017/09/09 11:43:08 ryoon Exp $
#

DISTNAME=		pinepgp-0.18.0
PKGREVISION=		5
CATEGORIES=		security mail
MASTER_SITES=		http://hany.sk/~hany/_data/pinepgp/
MASTER_SITES+=		http://terminus.sk/~hany/_data/pinepgp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://hany.sk/~hany/software/pinepgp/stable.html
COMMENT=		PGP display and sending filters for pine
LICENSE=		gnu-lgpl-v2.1

DEPENDS+=		bash>=2:../../shells/bash

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		cat
CONFIGURE_ENV+=		CAT=${TOOLS_CAT:Q}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
