# $NetBSD: Makefile,v 1.1.1.1 2002/02/15 01:10:53 hubertf Exp $
#

DISTNAME=	gtkmserv-0.5.2
CATEGORIES=	audio
MASTER_SITES=	http://projects.ubertechnique.com/downloads/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://projects.ubertechnique.com/index.html
COMMENT=	gtk-based GUI client for the audio/mserv package

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gtkMserv ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
