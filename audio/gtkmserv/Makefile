# $NetBSD: Makefile,v 1.7 2003/07/17 21:22:22 grant Exp $
#

DISTNAME=	gtkmserv-0.5.2
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	audio
MASTER_SITES=	http://projects.ubertechnique.com/downloads/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://projects.ubertechnique.com/index.html
COMMENT=	gtk-based GUI client for the audio/mserv package

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gtkMserv ${PREFIX}/bin

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
