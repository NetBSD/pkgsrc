# $NetBSD: Makefile,v 1.19 2004/10/03 00:13:00 tv Exp $
#

DISTNAME=	pdmenu_1.2.65
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.kitenet.net/programs/pdmenu/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.kitenet.net/programs/pdmenu/
COMMENT=	Simple console menu program

WRKSRC=		${WRKDIR}/pdmenu
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_PERL5=	YES

REPLACE_PERL=	examples/showdir.pl

USE_BUILDLINK3=		YES

CONFIGURE_ENV=	SLANG_LIB_LOC="${BUILDLINK_PREFIX.libslang}/lib"	\
		SLANG_H_LOC="${BUILDLINK_PREFIX.libslang}/include/slang.h"

pre-install:
	${SED} "s,.B /etc/pdmenurc,.B ${PREFIX}/etc/pdmenurc,g"		\
		${WRKSRC}/doc/pdmenurc.man > ${WRKSRC}/doc/pdmenurc.man.done
	${MV} ${WRKSRC}/doc/pdmenurc.man.done ${WRKSRC}/doc/pdmenurc.man
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pdmenu

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pdmenu
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pdmenu
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/pdmenu/newbie
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ANNOUNCE BUGS TODO \
		${PREFIX}/share/doc/pdmenu
	cd ${WRKSRC}/examples && ${INSTALL_DATA} README ba.lpd pdmenurc \
		pdmenurc.complex pdmenurc.monitor showdir.pl \
		${PREFIX}/share/examples/pdmenu
	cd ${WRKSRC}/examples/newbie && ${INSTALL_DATA} modem-check \
		pdmenurc.newbie	rpm-info-on-command \
		${PREFIX}/share/examples/pdmenu/newbie

.include "../../devel/libslang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
