# $NetBSD: Makefile,v 1.3 2003/07/13 13:50:43 wiz Exp $
#

DISTNAME=	transcalc-0.13
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://transcalc.sourceforge.net/
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=transcalc/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://transcalc.sourceforge.net
COMMENT=	Transmission line analysis/synthesis

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
