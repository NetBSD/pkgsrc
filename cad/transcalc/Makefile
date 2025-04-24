# $NetBSD: Makefile,v 1.68 2025/04/24 14:13:20 wiz Exp $
#

DISTNAME=	transcalc-0.14
PKGREVISION=	47
CATEGORIES=	cad
MASTER_SITES=	https://transcalc.sourceforge.net/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=transcalc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	https://transcalc.sourceforge.net/
COMMENT=	Transmission line analysis/synthesis

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
