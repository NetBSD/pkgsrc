# $NetBSD: Makefile,v 1.2 2003/05/02 11:53:59 wiz Exp $
#

DISTNAME=	transcalc-0.13
PKGREVISION=	1
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
