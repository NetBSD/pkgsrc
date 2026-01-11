# $NetBSD: Makefile,v 1.15 2026/01/11 05:33:44 wiz Exp $

DISTNAME=	nelma-3.2
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://www.tablix.org/~avian/nelma/
COMMENT=	Circuit board capacitance extraction tool

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
