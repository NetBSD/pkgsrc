# $NetBSD: Makefile,v 1.10 2004/04/11 17:17:50 xtraeme Exp $
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
USE_BUILDLINK3=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkMserv ${PREFIX}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
