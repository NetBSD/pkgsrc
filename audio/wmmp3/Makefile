# $NetBSD: Makefile,v 1.10 2006/10/04 20:44:20 wiz Exp $

DISTNAME=	wmmp3-0.12
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES= 	http://www.dotfiles.com/software/wmmp3/
# dotfiles is alive, but /software is gone

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.dotfiles.com/software/wmmp3/
COMMENT=	Front-end for mpg123 in a Window Maker dockapp

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123

GNU_CONFIGURE=	yes

post-patch:
	${MV} ${WRKSRC}/sample.wmmp3 ${WRKSRC}/sample.wmmp3.orig
	${SED} -e 's:/usr/local:'${LOCALBASE}':g' \
		${WRKSRC}/sample.wmmp3.orig > ${WRKSRC}/sample.wmmp3

post-install:
	@${ECHO} "===> Installing sample.wmmp3 in ${PREFIX}/share/examples"
	${INSTALL_DATA} ${WRKSRC}/sample.wmmp3 ${PREFIX}/share/examples

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
