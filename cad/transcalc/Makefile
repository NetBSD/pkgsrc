# $NetBSD: Makefile,v 1.66 2024/11/17 07:15:38 wiz Exp $
#

DISTNAME=	transcalc-0.14
PKGREVISION=	45
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
