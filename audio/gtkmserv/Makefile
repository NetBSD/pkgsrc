# $NetBSD: Makefile,v 1.15 2006/02/05 23:08:09 joerg Exp $
#

DISTNAME=	gtkmserv-0.5.2
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://projects.ubertechnique.com/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://projects.ubertechnique.com/index.html
COMMENT=	Gtk-based GUI client for the audio/mserv package

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkMserv ${PREFIX}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
