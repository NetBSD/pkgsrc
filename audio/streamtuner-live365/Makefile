# $NetBSD: Makefile,v 1.8 2003/12/13 00:45:21 wiz Exp $
#

DISTNAME=	streamtuner-live365-0.3.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/streamtuner-live365.pkg/0.3.2/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Live365 plugin for streamtuner

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/streamtuner/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
