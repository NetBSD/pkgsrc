# $NetBSD: Makefile,v 1.45 2024/05/06 08:40:25 jperkin Exp $
#

DISTNAME=		freesci-0.3.5
PKGREVISION=		15
CATEGORIES=		games
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://freesci.linuxgames.com/
COMMENT=		Interpreter for Sierra On-Line's SCI games

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		wish:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-ggi --without-directfb

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	.*/bin/wish
REPLACE.wish.new=	${PREFIX}/bin/wish
REPLACE_FILES.wish=	conf/freesci-setup

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/freesci
	${INSTALL_DATA} ${FILESDIR}/config ${DESTDIR}${PREFIX}/share/examples/freesci

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
#.include "../../mk/motif.buildlink3.mk"
#.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
