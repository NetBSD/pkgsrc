# $NetBSD: Makefile,v 1.6 2003/09/28 09:13:58 jlam Exp $
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
USE_NCURSES=	# redrawwin()

pre-configure:
	@${SED} -e "s/cfg.use_screen = 0/cfg.use_screen = 1/" \
		${WRKSRC}/src/config.c > ${WRKSRC}/src/config.c.new && \
		${MV} ${WRKSRC}/src/config.c.new ${WRKSRC}/src/config.c
	@${SED} -e "s/USE_SCREEN=0/USE_SCREEN=1/" \
		${WRKSRC}/src/vifmrc0.1 > ${WRKSRC}/src/vifmrc0.1.new && \
		${MV} ${WRKSRC}/src/vifmrc0.1.new ${WRKSRC}/src/vifmrc0.1

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
