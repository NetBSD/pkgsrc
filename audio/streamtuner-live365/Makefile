# $NetBSD: Makefile,v 1.12 2004/03/30 22:26:58 xtraeme Exp $
#

DISTNAME=	streamtuner-live365-0.3.4
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Live365 plugin for streamtuner

USE_BUILDLINK3=	    yes
USE_LIBTOOL=	    yes
USE_PKGLOCALEDIR=   yes
GNU_CONFIGURE=	    yes
USE_X11=	    yes

SHLIBTOOL_OVERRIDE=	libtool

.include "../../audio/streamtuner/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
