# $NetBSD: Makefile,v 1.6 2001/06/11 06:34:22 jlam Exp $

DISTNAME=	xchat-1.6.2
CATEGORIES=	chat x11 gnome
MASTER_SITES=	${HOMEPAGE}/files/source/1.6/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://xchat.org/
COMMENT=	X11 (X Window System) IRC client, using the GTK+ toolkit

DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	python>=2.0:../../lang/python

USE_GMAKE=	yes
USE_PERL5=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

pre-configure:
	@${TOUCH} ${WRKSRC}/stamp-h.in

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/xchat

.include "../../mk/bsd.pkg.mk"
