# $NetBSD: Makefile,v 1.1.1.1 2001/01/18 01:50:46 hubertf Exp $
# FreeBSD Id: ports/misc/pdmenu/Makefile,v 1.11 2001/01/16 17:31:42 sobomax Exp

DISTNAME=	pdmenu_1.2.65
PKGNAME=	pdmenu-1.2.65
CATEGORIES=	misc
MASTER_SITES=	http://kitenet.net/programs/code/pdmenu/

MAINTAINER=	zuntum@eik.pl
HOMEPAGE=	http://www.kitenet.net/programs/pdmenu/

DEPENDS+=	libslang-*:../../devel/libslang

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PERL5=	YES
WRKSRC=		${WRKDIR}/pdmenu

CONFIGURE_ENV=	SLANG_LIB_LOC='${PREFIX}/lib' \
		SLANG_H_LOC='${PREFIX}/include/slang.h'

post-patch:
		${SED} "s,@LOCALBASE@,${LOCALBASE},g" \
		< ${WRKSRC}/autoconf/makeinfo.in > ${WRKSRC}/autoconf/makeinfo.in.done
		${MV} ${WRKSRC}/autoconf/makeinfo.in.done ${WRKSRC}/autoconf/makeinfo.in

pre-install:
		${INSTALL_DATA_DIR} ${PREFIX}/lib/pdmenu

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pdmenu ${PREFIX}/share/examples/pdmenu \
			${PREFIX}/share/examples/pdmenu/newbie
		cd ${WRKSRC}/doc && ${INSTALL} -c -o root -g wheel ANNOUNCE BUGS TODO \
			pdmenu-1.2.65.lsm ${PREFIX}/share/doc/pdmenu
		cd ${WRKSRC}/examples && ${INSTALL} -c -o root -g wheel README ba.lpd \
			pdmenurc pdmenurc.complex pdmenurc.monitor showdir.pl \
			${PREFIX}/share/examples/pdmenu
		cd ${WRKSRC}/examples/newbie && ${INSTALL} -c -o root -g wheel \
			modem-check pdmenurc.newbie rpm-info-on-command \
				${PREFIX}/share/examples/pdmenu/newbie

.include "../../mk/bsd.pkg.mk"
