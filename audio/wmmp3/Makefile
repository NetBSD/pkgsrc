# $NetBSD: Makefile,v 1.2 2002/09/21 00:59:26 jlam Exp $

DISTNAME=	wmmp3-0.12
CATEGORIES=	audio
MASTER_SITES= 	http://www.dotfiles.com/software/wmmp3/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.dotfiles.com/software/wmmp3/
COMMENT=	front-end for mpg123 in a Window Maker dockapp

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_X11BASE=	yes

post-patch:
	${MV} ${WRKSRC}/sample.wmmp3 ${WRKSRC}/sample.wmmp3.orig
	${SED} -e 's:/usr/local:'${LOCALBASE}':g' \
		${WRKSRC}/sample.wmmp3.orig > ${WRKSRC}/sample.wmmp3

post-install:
	@${ECHO} "===> Installing sample.wmmp3 in ${PREFIX}/share/examples"
	${INSTALL_DATA} ${WRKSRC}/sample.wmmp3 ${PREFIX}/share/examples

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
