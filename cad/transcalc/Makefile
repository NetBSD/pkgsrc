# $NetBSD: Makefile,v 1.9 2004/10/03 00:13:13 tv Exp $
#

DISTNAME=	transcalc-0.13
PKGREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	http://transcalc.sourceforge.net/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=transcalc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://transcalc.sourceforge.net/
COMMENT=	Transmission line analysis/synthesis

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
