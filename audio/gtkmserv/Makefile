# $NetBSD: Makefile,v 1.21 2012/09/12 00:24:38 asau Exp $
#

DISTNAME=	gtkmserv-0.5.2
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	# http://projects.ubertechnique.com/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.ubertechnique.com/index.html
COMMENT=	Gtk-based GUI client for the audio/mserv package

WRKSRC=			${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=		YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtkMserv ${DESTDIR}${PREFIX}/bin

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
