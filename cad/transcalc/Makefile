# $NetBSD: Makefile,v 1.7 2004/01/22 07:21:55 grant Exp $
#

DISTNAME=	transcalc-0.13
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://transcalc.sourceforge.net/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=transcalc/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://transcalc.sourceforge.net/
COMMENT=	Transmission line analysis/synthesis

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
