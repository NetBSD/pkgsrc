# $NetBSD: Makefile,v 1.2 2002/02/26 01:37:20 wiz Exp $
#

DISTNAME=	gtkmserv-0.5.2
CATEGORIES=	audio
MASTER_SITES=	http://projects.ubertechnique.com/downloads/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://projects.ubertechnique.com/index.html
COMMENT=	gtk-based GUI client for the audio/mserv package

WRKSRC=			${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gtkMserv ${PREFIX}/bin

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
