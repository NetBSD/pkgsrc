# $NetBSD: Makefile,v 1.11 2004/03/26 02:27:34 wiz Exp $
#

DISTNAME=	streamtuner-live365-0.3.2
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/streamtuner-live365.pkg/0.3.2/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Live365 plugin for streamtuner

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

SHLIBTOOL_OVERRIDE=	libtool

.include "../../audio/streamtuner/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
