# $NetBSD: Makefile,v 1.14 2004/10/03 00:13:09 tv Exp $
#

DISTNAME=	streamtuner-live365-0.3.4
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/

MAINTAINER=	tech-pkg@NetBSD.org
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
