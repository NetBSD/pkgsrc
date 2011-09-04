# $NetBSD: Makefile,v 1.17 2011/09/04 21:38:03 dholland Exp $

DISTNAME=	wmmp3-0.12
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.dotfiles.com/software/wmmp3/

MAINTAINER=	rxg@NetBSD.org
# HOMEPAGE=	http://www.dotfiles.com/software/wmmp3/
COMMENT=	Front-end for mpg123 in a Window Maker dockapp

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123

GNU_CONFIGURE=	yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	share/examples

post-patch:
	${MV} ${WRKSRC}/sample.wmmp3 ${WRKSRC}/sample.wmmp3.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' \
		${WRKSRC}/sample.wmmp3.orig > ${WRKSRC}/sample.wmmp3

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample.wmmp3 \
		${DESTDIR}${PREFIX}/share/examples

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
