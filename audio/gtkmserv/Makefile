# $NetBSD: Makefile,v 1.9 2004/01/20 12:07:42 agc Exp $
#

DISTNAME=	gtkmserv-0.5.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://projects.ubertechnique.com/downloads/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://projects.ubertechnique.com/index.html
COMMENT=	Gtk-based GUI client for the audio/mserv package

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gtkMserv ${PREFIX}/bin

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
