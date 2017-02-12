# $NetBSD: Makefile,v 1.46 2017/02/12 06:25:07 ryoon Exp $
#

DISTNAME=	transcalc-0.14
PKGREVISION=	28
CATEGORIES=	cad
MASTER_SITES=	http://transcalc.sourceforge.net/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=transcalc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://transcalc.sourceforge.net/
COMMENT=	Transmission line analysis/synthesis

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
