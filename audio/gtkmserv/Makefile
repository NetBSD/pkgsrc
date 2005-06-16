# $NetBSD: Makefile,v 1.14 2005/06/16 06:57:38 jlam Exp $
#

DISTNAME=	gtkmserv-0.5.2
PKGREVISION=	3
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
