# $NetBSD: Makefile,v 1.18 2006/04/17 13:46:18 wiz Exp $
#

DISTNAME=	transcalc-0.14
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://transcalc.sourceforge.net/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=transcalc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://transcalc.sourceforge.net/
COMMENT=	Transmission line analysis/synthesis

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"
#.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
