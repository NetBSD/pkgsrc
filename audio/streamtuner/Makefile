# $NetBSD: Makefile,v 1.2 2003/03/04 14:41:17 salo Exp $
#

DISTNAME=	streamtuner-0.9.1
CATEGORIES=	audio www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=streamtuner/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://streamtuner.sourceforge.net/
COMMENT=	Stream directory browser

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/extras/streamtuner.pc.in

.include "../../www/curl/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
