# $NetBSD: Makefile,v 1.9 2002/01/01 17:36:28 wiz Exp $
#

DISTNAME=	${PKGNAME:S|-|_|}
PKGNAME=	pdmenu-1.2.65
CATEGORIES=	misc
MASTER_SITES=	http://kitenet.net/programs/code/pdmenu/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.kitenet.net/programs/pdmenu/
COMMENT=	Simple console menu program

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PERL5=	YES
WRKSRC=		${WRKDIR}/pdmenu

REPLACE_PERL=	examples/showdir.pl

USE_BUILDLINK_ONLY=	YES

CONFIGURE_ENV=	SLANG_LIB_LOC="${BUILDLINK_DIR}/lib"			\
		SLANG_H_LOC="${BUILDLINK_DIR}/include/slang.h"

pre-install:
	${SED} "s,.B /etc/pdmenurc,.B ${PREFIX}/etc/pdmenurc,g"		\
		${WRKSRC}/doc/pdmenurc.man > ${WRKSRC}/doc/pdmenurc.man.done
	${MV} ${WRKSRC}/doc/pdmenurc.man.done ${WRKSRC}/doc/pdmenurc.man
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pdmenu

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pdmenu \
		${PREFIX}/share/examples/pdmenu	\
		${PREFIX}/share/examples/pdmenu/newbie
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ANNOUNCE BUGS TODO \
		${PREFIX}/share/doc/pdmenu
	cd ${WRKSRC}/examples && ${INSTALL_DATA} README ba.lpd pdmenurc \
		pdmenurc.complex pdmenurc.monitor showdir.pl \
		${PREFIX}/share/examples/pdmenu
	cd ${WRKSRC}/examples/newbie && ${INSTALL_DATA} modem-check \
		pdmenurc.newbie	rpm-info-on-command \
		${PREFIX}/share/examples/pdmenu/newbie

.include "../../devel/libslang/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
