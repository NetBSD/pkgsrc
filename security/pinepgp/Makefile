# $NetBSD: Makefile,v 1.20 2020/01/26 17:32:06 rillig Exp $
#

DISTNAME=		pinepgp-0.18.0
PKGREVISION=		5
CATEGORIES=		security mail
MASTER_SITES=		http://hany.sk/~hany/_data/pinepgp/
MASTER_SITES+=		http://terminus.sk/~hany/_data/pinepgp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://hany.sk/~hany/software/pinepgp/stable.html
COMMENT=		PGP display and sending filters for pine
LICENSE=		gnu-lgpl-v2.1

DEPENDS+=		bash>=2:../../shells/bash

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		cat
CONFIGURE_ENV+=		CAT=${TOOLS_CAT:Q}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
