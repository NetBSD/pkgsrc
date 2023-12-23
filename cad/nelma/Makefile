# $NetBSD: Makefile,v 1.13 2023/12/23 02:02:48 zafer Exp $
#

DISTNAME=	nelma-3.2
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	#

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	https://www.tablix.org/~avian/nelma/
COMMENT=	Circuit board capacitance extraction tool

USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/confuse/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
