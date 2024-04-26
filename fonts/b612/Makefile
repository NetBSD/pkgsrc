# $NetBSD: Makefile,v 1.1 2024/04/26 19:56:23 wiz Exp $

DISTNAME=	b612-1.008
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=polarsys/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/polarsys/b612/
COMMENT=	Eclipse PolarSys B612 font family
# "This program and the accompanying materials are made available
# under the terms of the Eclipse Public License v2.0 and Eclipse
# Distribution License v1.0 and the SIL Open Font License v1.1 which
# accompanies this distribution."
# Unclear if this is intended as "AND" or "OR". Upstream bug report
# is not answered:
# https://github.com/polarsys/b612/issues/23
#LICENSE=	epl-v1.0 OR epl-v2.0 OR ofl-v1.1
LICENSE=	epl-v1.0 AND epl-v2.0 AND ofl-v1.1

do-build:

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
