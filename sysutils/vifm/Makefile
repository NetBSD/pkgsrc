# $NetBSD: Makefile,v 1.7 2003/12/28 00:11:45 wiz Exp $
#

DISTNAME=	vifm-0.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vifm/}

MAINTAINER=	swalter@lettermax.de
HOMEPAGE=	http://vifm.sourceforge.net/
COMMENT=	Ncurses based file manager with vi like keybindings

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[.-_]*
INCOMPAT_CURSES=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-C]*

pre-configure:
	@${SED} -e "s/cfg.use_screen = 0/cfg.use_screen = 1/" \
		-e "s,/usr/local,${PREFIX},g" \
		${WRKSRC}/src/config.c > ${WRKSRC}/src/config.c.new && \
		${MV} ${WRKSRC}/src/config.c.new ${WRKSRC}/src/config.c
	@${SED} -e "s/USE_SCREEN=0/USE_SCREEN=1/" \
		${WRKSRC}/src/vifmrc0.1 > ${WRKSRC}/src/vifmrc0.1.new && \
		${MV} ${WRKSRC}/src/vifmrc0.1.new ${WRKSRC}/src/vifmrc0.1

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
