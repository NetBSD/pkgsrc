# $NetBSD: Makefile,v 1.16 2000/11/16 21:50:14 tron Exp $

DISTNAME=	xchat-1.5.7
CATEGORIES=	net x11 gnome
MASTER_SITES=	${HOMEPAGE}/files/source/1.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://xchat.org/

DEPENDS+=	gnome-core>=1.0.55:../../x11/gnome-core
DEPENDS+=	python>=1.5.2:../../lang/python

USE_GMAKE=	yes
USE_PERL5=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include LIBS=-lutil

pre-configure:
	@${TOUCH} ${WRKSRC}/stamp-h.in

post-install:
	${MKDIR} ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/xchat

.include "../../mk/bsd.pkg.mk"
