# $NetBSD: Makefile,v 1.3 2001/02/05 15:30:22 dmcmahill Exp $

DISTNAME=	xchat-1.6.2
CATEGORIES=	chat x11 gnome
MASTER_SITES=	${HOMEPAGE}/files/source/1.6/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://xchat.org/

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	python>=2.0:../../lang/python

USE_GMAKE=	yes
USE_PERL5=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include

pre-configure:
	@${TOUCH} ${WRKSRC}/stamp-h.in

post-install:
	${MKDIR} ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/xchat

.include "../../mk/bsd.pkg.mk"
