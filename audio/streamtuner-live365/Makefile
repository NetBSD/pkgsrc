# $NetBSD: Makefile,v 1.5 2003/07/13 13:50:28 wiz Exp $
#

DISTNAME=	streamtuner-live365-0.3.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=streamtuner/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Live365 plugin for streamtuner

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/streamtuner/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
