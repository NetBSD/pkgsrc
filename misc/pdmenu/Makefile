# $NetBSD: Makefile,v 1.7 2001/04/28 12:44:57 zuntum Exp $
# FreeBSD Id: ports/misc/pdmenu/Makefile,v 1.11 2001/01/16 17:31:42 sobomax Exp

DISTNAME=	${PKGNAME:S|-|_|}
PKGNAME=	pdmenu-1.2.65
CATEGORIES=	misc
MASTER_SITES=	http://kitenet.net/programs/code/pdmenu/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.kitenet.net/programs/pdmenu/
COMMENT=	Simple console menu program

DEPENDS+=	libslang-*:../../devel/libslang

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PERL5=	YES
WRKSRC=		${WRKDIR}/pdmenu

CONFIGURE_ENV=	SLANG_LIB_LOC="${LOCALBASE}/lib"					\
		SLANG_H_LOC="${LOCALBASE}/include/slang.h"

MAKE_ENV+=	LIBS="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib"

pre-install:
	${SED} "s,.B /etc/pdmenurc,.B ${PREFIX}/etc/pdmenurc,g"				\
		${WRKSRC}/doc/pdmenurc.man > ${WRKSRC}/doc/pdmenurc.man.done
	${MV} ${WRKSRC}/doc/pdmenurc.man.done ${WRKSRC}/doc/pdmenurc.man
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pdmenu

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pdmenu ${PREFIX}/share/examples/pdmenu	\
		${PREFIX}/share/examples/pdmenu/newbie
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ANNOUNCE BUGS TODO pdmenu-1.2.65.lsm 	\
		${PREFIX}/share/doc/pdmenu
	cd ${WRKSRC}/examples && ${INSTALL_DATA} README ba.lpd pdmenurc pdmenurc.complex\
		pdmenurc.monitor showdir.pl ${PREFIX}/share/examples/pdmenu
	cd ${WRKSRC}/examples/newbie && ${INSTALL_DATA} modem-check pdmenurc.newbie	\
		rpm-info-on-command ${PREFIX}/share/examples/pdmenu/newbie

.include "../../mk/bsd.pkg.mk"
